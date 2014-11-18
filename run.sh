#!/bin/bash
bin/hadoop jar video/call_app.jar com.smc.vidproc.DirectVideoProcessor -files cpu/face_detect/libcpu_app.so,gpu/face_detect/libgpu_app.so input output
