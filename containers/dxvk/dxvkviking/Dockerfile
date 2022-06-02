# vkcube sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vkcube .
# xhost +si:localuser:root

# Docker >= 19.03
# docker run --gpus all -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

# Docker < 19.03
# docker run --runtime=nvidia -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

FROM nvidia/vulkan:1.1.121

ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES},display


# We maybe need this?
RUN rm /etc/apt/sources.list.d/cuda.list
RUN rm /etc/apt/sources.list.d/nvidia-ml.list

# For now, keep all of these 
RUN apt-get update && apt-get install -y --no-install-recommends \ 
    build-essential \
    cmake \
    clang \
    software-properties-common \
    git \
    python3 \
    python3-pip \
    x11-utils \
    x11-xserver-utils \
    gcc-multilib \
    g++-multilib \
    libx11-dev \
    mesa-common-dev \
    cabextract \
    xterm \
    libx11-xcb-dev \
    libxkbcommon-dev \
    libwayland-dev \
    libxrandr-dev \
    wayland-protocols && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && \
    apt-get install wget && \
    dpkg --add-architecture i386 && \
    wget -qO - https://dl.winehq.org/wine-builds/winehq.key | apt-key add - && \
    apt-add-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ bionic main' && \
    add-apt-repository ppa:cybermax-dexter/sdl2-backport && \ 
    apt update && \
    apt install -y --install-recommends winehq-stable wine64

RUN ln -s /usr/bin/python3 /usr/bin/python && \
    git clone https://github.com/KhronosGroup/Vulkan-Tools.git /opt/Vulkan-Tools && \
    cd /opt/Vulkan-Tools && \
    mkdir build && cd build && \
    python ../scripts/update_deps.py && \
    cmake -C helper.cmake .. && \
    cmake --build . && \
    make install 

# install DXVK in the container
RUN git clone https://github.com/doitsujin/dxvk /opt/DXVK && \
    cd /opt/DXVK && \
    sh setup_dxvk.sh install; exit 0

RUN wget  https://raw.githubusercontent.com/Winetricks/winetricks/master/src/winetricks && \
    chmod +x winetricks && \
    mv -v winetricks /usr/local/bin && \
    winetricks dxvk
    
# Install Viking Benchmark
RUN apt-get install unzip && \
    wget -P /opt/viking https://www.dropbox.com/s/boe80e5hoo17opi/Viking_Windows.zip && \
    cd /opt/viking && \
    unzip Viking_Windows.zip

# Install libstrangle 
RUN echo "rebuild" && \ 
    echo "rebuild" && \ 
    git clone https://github.com/ErwinRussel/libstrangle.git /opt/strangle && \
    cd /opt/strangle && \
    make && \
    make install && \
    pip3 install -r promclient/requirements.txt
    
# Create a directory for dumping benchmark and later to mount to
RUN mkdir /opt/output

WORKDIR /opt/viking/Viking_Windows

ENV WINEDEBUG=-all
ENV WINEDLLOVERRIDES="dxgi=n"

CMD nohup bash -c "python3 /opt/strangle/promclient/promclient.py &" && \
    if [ $(xrandr | grep \* | cut -d' ' -f4) = ${RESOLUTION} ]; \ 
    then echo "Resolution already $RESOLUTION"; \ 
    else xrandr -s ${RESOLUTION}; fi && \
    sleep ${SLEEP} && \
    echo 'Benchmark started' && \
    strangle ${FPS} wine Viking_Village.exe > /dev/null && \
    mv ./fps.csv /opt/output/fps.csv && \
    cat benchmark.txt

