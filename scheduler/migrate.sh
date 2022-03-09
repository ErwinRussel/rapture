# This file is for migrating a container between two nodes. 
# The inputs will be:
# - Source Host Ip
# - Target Host Ip
# - Source Host Docker ID 
# Later on more will be expanded to accomodate things like external 
# ports and GPU capabilities
# Remote calls will be done via SSH and File transfer will be done via Rsync
# TODO: check if rsync is installed on target machine 
# SRC_IP = arg1
# TRG_IP = arg2 
# SRC_CID = arg3 

while getopts u:s:t:c: flag
do
    case "${flag}" in
        u) USER=${OPTARG};;
        s) SRC_IP=${OPTARG};;
        t) TRG_IP=${OPTARG};;
        c) SRC_CID=${OPTARG};;
    esac
done

echo $USER
echo $SRC_IP 
echo $TRG_IP
echo $SRC_CID

# 0. Get source image from container id
ssh $USER@$SRC_IP "
sudo docker inspect $SRC_CID | grep Image
"

# 1. Create similar container on Target 
# TODO: a. create user b. start X server 
TRG_CID = ssh $USER@$TRG_IP "sudo docker create $SRC_IMG" # save remote docker id to variable

# 1.5 debug logs host1
ssh $USER@$SRC_IP "
sudo docker logs $SRC_CID
"

# 2. Checkpoint container 
# TODO: stop or dont stop?
ssh $USER@$SRC_IP "
docker checkpoint create --checkpoint-dir=/home/opt/container-checkpoints looper checkpoint1 && \
rsync -P --recursive --rsh=ssh  /home/opt/container-checkpoints/checkpoint1 \ 
user@host2:/var/lib/docker/containers/$TRG_CID/checkpoints/checkpoint1
"

# 3.
ssh $USER@$TRG_IP "
sudo docker start --checkpoint=checkpoint $TRG_CID
"

#3.5 debug logs host2
ssh $USER@$TRG_IP "
sudo docker logs $TRG_CID
"