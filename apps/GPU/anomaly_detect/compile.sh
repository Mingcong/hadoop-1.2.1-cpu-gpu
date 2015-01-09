#!/bin/bash
g++ gpu_anomaly_detect.cpp -o gpu_anomaly_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
