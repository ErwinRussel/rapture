USERNAME=erwin_erwinrussel_com
HOST2=10.148.0.4



# docker run --gpus all -ti --privileged --rm -e DISPLAY \
# -v /tmp/.X11-unix:/tmp/.X11-unix \
# -v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
# erwinrussel/atlasgears:nvglrestore

CID=$(docker run --gpus all -ti --privileged -d --rm -e DISPLAY=:0 \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
erwinrussel/atlasgears:nvglrestore)

echo $CID

# ssh $USERNAME@$HOST1 ffmpeg -video_size 1920x1080 -framerate 30 -f x11grab -i :0 -pix_fmt yuv420p -vf source.mp4 &
# ssh $USERNAME@$HOST2 ffmpeg -video_size 1920x1080 -framerate 30 -f x11grab -i :0 -pix_fmt yuv420p -vf target.mp4 &

sleep 10

echo "Running Checkpoint Script"
docker exec $CID sh checkpoint.sh


echo "Restoring"
sudo docker run --gpus all --privileged -d --rm -e DISPLAY=:1 \
-e ATL_RESTORE=1 \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
erwinrussel/atlasgears:nvglrestore 

sudo docker stop $CID

# sudo apt install ffmpeg

# ffmpeg -video_size 1920x1080 -framerate 30 -f x11grab -i :0 -pix_fmt yuv420p -vf output.mp4


# sudo docker run --gpus all -ti --cap-add=ALL --rm -e DISPLAY \
# -v /tmp/.X11-unix:/tmp/.X11-unix \
# -v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
# erwinrussel/atlasgears:nvglrestore 


# 10.148.0.2:/home/erwin_erwinrussel_com/checkpoints      /home/erwin_erwinrussel_com/checkpoints nfs4    defaults,user,exec      0 0