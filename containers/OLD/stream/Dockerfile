# vkcube sample compiled from https://github.com/KhronosGroup/Vulkan-Tools

# docker build -t vkcube .
# xhost +si:localuser:root

# Docker >= 19.03
# docker run --gpus all -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

# Docker < 19.03
# docker run --runtime=nvidia -ti --rm -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix vkcube

FROM nvidia/vulkan:1.1.121

ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES},display

# For now, keep all of these 
RUN apt-get update && apt-get install -y --no-install-recommends \ 
    build-essential \
    cmake \
    clang \
    software-properties-common \
    git \
    python3 \
    x11-utils \
    cabextract \
    xterm && \
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
    
# the link will change on 1 nov
RUN apt-get install unzip && \
    wget -P /opt/viking https://filebin.net/uf4v3x7h8380sxj2/Viking_Windows.zip && \
    cd /opt/viking && \
    unzip Viking_Windows.zip

WORKDIR /opt/viking/Viking_Windows

ENV WINEDEBUG=-all
ENV WINEDLLOVERRIDES="dxgi=n,d3d11=n"

# Start the benchmark? libstrangle the process?
CMD wine Viking_Village.exe && \
    cat benchmark.txt

# Get process id and window
# Stream this window 



