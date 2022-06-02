FROM nvidia/cuda:11.0-base

RUN apt-get update && apt-get install -y --no-install-recommends \
    wget 

RUN VERSION=0.3.0 && \
    wget https://github.com/utkuozdemir/nvidia_gpu_exporter/releases/download/v${VERSION}/nvidia_gpu_exporter_${VERSION}_linux_x86_64.tar.gz && \
    tar -xvzf nvidia_gpu_exporter_${VERSION}_linux_x86_64.tar.gz && \
    mv nvidia_gpu_exporter /usr/local/bin 

EXPOSE 9835
ENTRYPOINT ["/usr/local/bin/nvidia_gpu_exporter"]