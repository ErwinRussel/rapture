
while getopts u:s:t:c: flag
do
    case "${flag}" in
        t) TRG_IP=${OPTARG};;
        c) SRC_CID=${OPTARG};;
    esac
done

echo $TRG_IP
echo $SRC_CID

# -- PRE-MIGRATE ---
# Get Source image from docker
SRC_IMG=sudo docker inspect $SRC_CID | grep -oP '(?<='sha256:')(.*)(?='\"')'

# The source prepares a container on the target
TRG_CID=ssh $USER@$TRG_IP "sudo docker create ${SRC_IMG}"

# The source opens the nfs file directory for the target in the source checkpoint folder and the target container checkpoint folder
sudo mkdir /opt/checkpoints/${SRC_CID}
sudo chown nobody:nogroup /opt/checkpoints/${SRC_CID}
sudo chmod 777 /opt/checkpoints/${SRC_CID}//opt/checkpoints/${SRC_CID}
echo "Folder created"
ssh $USER@$TRG_IP "sudo mount -t nfs -o vers=4 -o resvport ${SRC_IP}:/opt/checkpoints/${SRC_CID}  /var/lib/docker/containers/${TRG_CID}/checkpoints" 
echo "Container and NFS connection set up"

echo "Everything set-up, press key to checkpoint-migrate-restor"
read r
# -- MIGRATE -- 
# Checkpoint container 
sudo docker checkpoint create $SRC_CID cr1
ssh $USER@$TRG_IP "sudo docker restore --checkpoint=cr1 ${SRC_IMG}"

# sudo apt install nfs-kernel-server nfs-common
# sudo docker inspect $SRC_ID | grep -o 'sha256:\(.*\)"'
