FROM nvidia/vulkan:1.1.121

RUN apt-get update && apt-get install mesa-utils --no-install-recommends -y 

RUN apt-get install ca-certificates wget libxt6 xauth x11-xkb-utils xkb-data --no-install-recommends -y 

RUN apt-get update && apt-get install -y -qq --no-install-recommends \
    libglvnd0 \
    libgl1 \
    libglx0 \
    libegl1 \
    libxext6 \
    libx11-6 \
    libxtst6 \
    libxv1 \
    libegl1-mesa \
    libglu1-mesa \
    && rm -rf /var/lib/apt/lists/*

CMD glxgears