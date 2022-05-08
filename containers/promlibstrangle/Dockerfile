# port 6463 for libstrangle
# Bind to X server

FROM ubuntu:18.04

# Get all the stuff for glxgears, git, make 
RUN apt-get update && apt-get install mesa-utils --no-install-recommends -y 

RUN apt-get install git ca-certificates build-essential libglu1-mesa-dev freeglut3-dev mesa-common-dev --no-install-recommends -y 

# promdockerthing

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

ENV DISPLAY=:0

CMD strangle 20 glxgears