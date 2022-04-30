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
echo "Run source and fill in source container ID"
read SRC_CID

# 0. Get source image from container id
# gcloud compute ssh --zone "us-central1-a" "instance-3" \
#  --project "thesis-324221" \
#  --command="sudo docker inspect ${SRC_CID} | grep Image"


# echo "Fill in source image"
# read SRC_IMG
# # # 1. Create similar container on Target 
# # # TODO: a. create user b. start X server 
# TRG_CID=$(gcloud compute ssh --zone "us-central1-a" "instance-4" \
#  --project "thesis-324221" \
#  --command="sudo docker create busybox /bin/sh -c 'i=0; while true; do echo $i; i=$(expr $i + 1); sleep 5; done'") # save remote docker id to variable

echo "target container and fill in target image"
read TRG_CID

# # 2. Checkpoint container 
# # TODO: stop or dont stop?
gcloud compute ssh --zone "us-central1-a" "instance-3" \
 --project "thesis-324221" \
 --command="sudo docker checkpoint create --checkpoint-dir=/home/opt/container-checkpoints looper checkpoint1 && \ 
 sudo tar -zcvf /home/erwin_erwinrussel_com/checkpoint1.tar.gz /home/opt/container-checkpoints/checkpoint1"

 # # 1.5 debug logs host1
gcloud compute ssh --zone "us-central1-a" "instance-3" \
 --project "thesis-324221" \
 --command="sudo docker logs ${SRC_CID}"

echo "File location"
echo "/home/erwin_erwinrussel_com/checkpoint1.tar.gz"
echo "Command to run and untar"
echo "sudo mkdir -p /var/lib/docker/containers/${TRG_CID}/checkpoints/checkpoint1 && \
sudo tar -C /var/lib/docker/containers/${TRG_CID}/checkpoints/checkpoint1 -xvf ./checkpoint1.tar.gz && \
sudo mv /var/lib/docker/containers/${TRG_CID}/checkpoints/checkpoint1/home/opt/container-checkpoints/checkpoint1 /var/lib/docker/containers/${TRG_CID}/checkpoints/ && \
sudo docker start --checkpoint checkpoint1 looper"

#  && \
# rsync -P --recursive --rsh=ssh  /home/opt/container-checkpoints/checkpoint1 \ 
# user@host2:/var/lib/docker/containers/$TRG_CID/checkpoints/checkpoint1

# gcloud compute scp --recurse instance-3:/home/opt/container-checkpoints/checkpoint1 instance-4:/home/opt/test/checkpoint1 \
# --zone "us-central1-a" \
# --project "thesis-324221" 

# gcloud compute scp --recurse root@instance-3:/home/opt/container-checkpoints/checkpoint1 ./checktmp/checkpoint1 \
# --zone "us-central1-a" \
# --project "thesis-324221" 

# gcloud compute scp --recurse ./checktmp/checkpoint1 root@instance-4:/home/opt/test/checkpoint1 \
# --zone "us-central1-a" \
# --project "thesis-324221" 


# # 3.
# ssh $USER@$TRG_IP "
# sudo docker start --checkpoint=checkpoint $TRG_CID
# "

# #3.5 debug logs host2
# ssh $USER@$TRG_IP "
# sudo docker logs $TRG_CID
