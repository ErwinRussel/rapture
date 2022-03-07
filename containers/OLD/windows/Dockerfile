# Sample Dockerfile

# Indicates that the windowsservercore image will be used as the base image.
FROM mcr.microsoft.com/windows/nanoserver

# Install Direct3D11

# Install Viking Benchmark --> needs unzip
RUN wget -P /opt/viking https://www.dropbox.com/s/0b3ow0iwew770a8/Viking_Windows.zip && \
    cd /opt/viking && \
    Expand-Archive -Path .\Viking_Windows.zip

WORKDIR /opt/viking/Viking_Linux

# Sets a command or process that will run each time a container is run from the new image.
CMD [ "cmd" ]


