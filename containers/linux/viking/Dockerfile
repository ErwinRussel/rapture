# vkcube sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vkcube .
# xhost +si:localuser:root

# Docker >= 19.03
# docker run --gpus all -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

# Docker < 19.03
# docker run --runtime=nvidia -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

FROM nvidia/vulkan:1.1.121

ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES},display

# we need this ffor some reason?
RUN rm /etc/apt/sources.list.d/cuda.list
RUN rm /etc/apt/sources.list.d/nvidia-ml.list

# For now, keep all of these 
RUN apt-get update && apt-get install -y --no-install-recommends \ 
    build-essential \
    cmake \
    clang \
    git \
    python3 \
    python3-pip \
    x11-utils \
    x11-xserver-utils \
    gcc-multilib \
    g++-multilib \
    libx11-dev \
    mesa-common-dev \
    xterm \
    libx11-xcb-dev \
    libxkbcommon-dev \
    libwayland-dev \
    libxrandr-dev \
    wayland-protocols && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/bin/python3 /usr/bin/python && \
    git clone https://github.com/KhronosGroup/Vulkan-Tools.git /opt/Vulkan-Tools && \
    cd /opt/Vulkan-Tools && \
    git checkout d15ff77bda1ef895ea5cf23d19472b7442e878cb && \
    mkdir build && cd build && \
    python ../scripts/update_deps.py && \
    cmake -C helper.cmake .. && \
    cmake --build . && \
    make install 

# install viking benchmark
RUN apt-get update && \
    apt-get install wget && \
    wget -P /opt/viking https://www.dropbox.com/s/bq2ynvkk5d1mq8b/viking_vulkan.tar.gz && \
    cd /opt/viking && \
    tar -xvf viking_vulkan.tar.gz && \
    cd Viking_Vulkan && \
    chmod +x Viking_Village.x86_64

# Install libstrangle 
RUN echo "rebuild4" && \
    git clone https://github.com/ErwinRussel/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install && \
    pip3 install -r promclient/requirements.txt

# problibstrangle done 

# Create a directory for dumping benchmark and later to mount to
RUN mkdir /opt/output

WORKDIR /opt/viking/Viking_Vulkan

CMD nohup bash -c "python3 /opt/strangle/promclient/promclient.py &" && \
    if [ $(xrandr | grep \* | cut -d' ' -f4) = ${RESOLUTION} ]; \ 
    then echo "Resolution already $RESOLUTION"; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    sleep ${SLEEP} && \
    echo 'Benchmark started' && \
    strangle ${FPS} ./Viking_Village.x86_64 > /dev/null && \
    mv ./fps.csv /opt/output/fps.csv && \
    cat benchmark.txt




