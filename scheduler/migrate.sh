
# For migration to run make sure that you have run # sudo apt install nfs-kernel-server nfs-common
while getopts s:t:c: flag
do
    case "${flag}" in
        s) SRC_IP=${OPTARG};;
        t) TRG_IP=${OPTARG};;
        c) SRC_CID=${OPTARG};;
    esac
done

echo "Preparing migration for container: ${SRC_CID} to host ${TRG_IP}"
# -- PRE-MIGRATE ---
echo "--------------------\n---- PRE-MIGRATE ---\n--------------------"
# Get Source image from docker
SRC_IMG=$(docker inspect "$SRC_CID" | grep -oP '(?<='sha256:')(.*)(?='\"')')
echo "- Source Image:"
echo $SRC_IMG

# The source prepares a container on the target
TRG_CID=$(ssh -i ${SSH_KEY} ${USR}@${TRG_IP} "sudo docker create ${SRC_IMG}")
echo "- Target container created, target container:"
echo $TRG_CID

# The source opens the nfs file directory for the target in the source checkpoint folder and the target container checkpoint folder
echo "- Making directory.."
mkdir /opt/checkpoints/${SRC_CID}
echo "- Adding permissions to directory.."
chown nobody:nogroup /opt/checkpoints/${SRC_CID}
echo "- Changing permissions to directory.."
chmod -R 777 /opt/checkpoints/${SRC_CID}
echo "- Folder created"
echo "/opt/checkpoints/${SRC_CID} *(rw,sync,no_subtree_check)" >> /etc/exports
echo "- Added to exports"
echo "- Restarting NFS"
sudo systemctl restart nfs-kernel-server
echo "- Current shared directories by NFS:"
sudo exportfs
#echo "Press any key to connect nfs on target container"
#read y

ssh -i ${SSH_KEY} ${USR}@${TRG_IP} "sudo mount -t nfs -o vers=4 -o resvport ${SRC_IP}:/opt/checkpoints/${SRC_CID}  /var/lib/docker/containers/${TRG_CID}/checkpoints"
echo "- Container and NFS connection set up"

echo "\n\n- Everything set-up, press any key to checkpoint-migrate-restore"
read r

# -- MIGRATE --
# start_time=$(date +%s.%3N)
echo "--------------------\n------ MIGRATE -----\n--------------------"
# Checkpoint container 
sudo docker checkpoint create ${SRC_CID} --checkpoint-dir /opt/checkpoints/${SRC_CID} cr1
chmod -R 777 /opt/checkpoints/${SRC_CID}
ssh -i ${SSH_KEY} ${USR}@${TRG_IP} "sudo docker start --checkpoint=cr1 ${TRG_CID}"
# end_time=$(date +%s.%3N)
# elapsed=$($end_time - $start_time)
# echo "- Migration succesful in: ${elapsed} seconds."
echo "- Logs:"
ssh -i ${SSH_KEY} ${USR}@${TRG_IP} "sudo docker logs ${TRG_CID}"

