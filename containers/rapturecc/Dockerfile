# docker run --rm -it -v /var/run/docker.sock:/var/run/docker.sock erwinrussel/rapturecc:latest docker ps

# FROM alpine:3.10

# RUN apk add --update docker openrc

# RUN rc-update add docker boot

FROM alpine:3.11

RUN apk update && apk add --no-cache docker-cli

