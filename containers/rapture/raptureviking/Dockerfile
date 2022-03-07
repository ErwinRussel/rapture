# Using the rapturebase docker file we try to install the vulkanviking 

FROM  erwinrussel/rapturebase:latest

RUN apt-get update && \
    apt-get install wget && \
    wget -P /opt/viking https://www.dropbox.com/s/hk80lbdujzpfp72/Viking_Linux.tar.gz && \
    cd /opt/viking && \
    tar -xvf Viking_Linux.tar.gz && \
    cd Viking_Linux && \
    chmod +x Viking_Village.x86_64

WORKDIR /opt/viking/Viking_Linux

CMD if [ $(xrandr | grep \* | cut -d' ' -f4) = "1920x1080" ]; \ 
    then echo 'Resolution already HD'; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    sleep ${SLEEP} && \
    strangle ${FPS} ./Viking_Village.x86_64 > /dev/null && \
    cat benchmark.txt