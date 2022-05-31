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
# RUN git clone https://gitlab.com/torkel104/libstrangle.git /opt/strangle && \
#     cd /opt/strangle && \
#     make && \
#     make install 

# promlibstrangle 
RUN set -x && \
    apt-get update && \
    apt-get install -y apt-utils software-properties-common clang-format && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update -y && \
    apt-get install -y curl tar build-essential git pkg-config gdb valgrind gcc-10 libmicrohttpd-dev doxygen graphviz && \
    rm -f /usr/bin/gcc && \
    ln -s /usr/bin/gcc-10 /usr/bin/gcc && \
    curl -sL https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-3.14.5-Linux-x86_64.tar.gz | tar xzf - -C /opt && \
    cp /opt/cmake-3.14.5-Linux-x86_64/bin/* /usr/local/bin/ && \
    cp -R /opt/cmake-3.14.5-Linux-x86_64/share/cmake-3.14 /usr/local/share/ && \
    curl -sL https://dl.google.com/go/go1.16.7.linux-amd64.tar.gz 2> /dev/null | tar xzf - -C /usr/local && \
    mkdir -p /gopath/{src,bin} && \
    printf 'export GOPATH=/gopath\nexport PATH=$PATH:/usr/local/go/bin:/gopath/bin\n' > /root/.bash_profile && \
    printf '#!/usr/bin/env bash\nsource /root/.bash_profile\nexec /bin/bash $@\n' > /entrypoint && \
    chmod +x /entrypoint && \
    GOPATH=/gopath /usr/local/go/bin/go get github.com/prometheus/prom2json && \
    GOPATH=/gopath /usr/local/go/bin/go install github.com/prometheus/prom2json/cmd/prom2json@latest && \
    GOPATH=/gopath /usr/local/go/bin/go get github.com/git-chglog/git-chglog && \
    GOPATH=/gopath /usr/local/go/bin/go install github.com/git-chglog/git-chglog/cmd/git-chglog@latest && \
    rm -rf /var/lib/apt/lists/*

# Install libstrangle 
RUN git clone https://github.com/ErwinRussel/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install 


# problibstrangle done 

# Create a directory for dumping benchmark and later to mount to
RUN mkdir /opt/output

WORKDIR /opt/viking/Viking_Vulkan

CMD if [ $(xrandr | grep \* | cut -d' ' -f4) = ${RESOLUTION} ]; \ 
    then echo "Resolution already $RESOLUTION"; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    sleep ${SLEEP} && \
    echo 'Benchmark started' && \
    strangle ${FPS} ./Viking_Village.x86_64 > /dev/null && \
    mv ./fps.csv /opt/output/fps.csv && \
    cat benchmark.txt




