#!/bin/bash
bin/hadoop jar video/face_jni_gpu.jar com.smc.vidproc.DirectVideoProcessor -files cpu/face_detect/libcpu_face_detect.so,gpu/face_detect/libgpu_face_detect.so input output
