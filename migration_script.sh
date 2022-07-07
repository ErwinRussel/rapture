USERNAME=erwin_erwinrussel_com
HOST1=10.128.0.53
HOST2=10.128.0.58

CID=ssh $USERNAME@$HOST1 sudo docker run --gpus all -ti --cap-add=ALL -d --rm -e DISPLAY \ 
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
erwinrussel/atlasgears:nvgl

sleep(10)

ssh $USERNAME@$HOST1 sudo docker exec $CID sh checkpoint.sh

ssh $USERNAME@$HOST2 sudo docker run --gpus all -ti --cap-add=ALL -d --rm -e DISPLAY \ 
-e ATL_RESTORE=1 \
-v /tmp/.X11-unix:/tmp/.X11-unix \
-v /home/erwin_erwinrussel_com/checkpoints:/atlas/checkpoints:rw \
erwinrussel/atlasgears:nvgl