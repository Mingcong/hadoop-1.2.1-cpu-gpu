#!/bin/bash
g++ gpu_pedestrian_detect.cpp -o gpu_pedestrian_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
