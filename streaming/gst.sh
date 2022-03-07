#!/bin/sh --> change the xid to the window
gst-launch-1.0 \
  ximagesrc ! \
    video/x-raw,framerate=60/1 ! \
    videoscale ! videorate ! videoconvert ! \
    vp8enc error-resilient=1 ! \
    rtpvp8pay ! udpsink host=127.0.0.1 port=5004

#gst-launch-1.0 \
#  ximagesrc ! \
#    video/x-raw,framerate=60/1 ! \
#    videoscale ! videorate ! videoconvert ! \
#    x264enc profile=baseline ! rtph264pay config-interval=1 pt=96 ! \
#    udpsink host=127.0.0.1 port=5004

