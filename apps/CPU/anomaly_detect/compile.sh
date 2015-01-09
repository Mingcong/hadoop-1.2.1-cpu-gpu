#!/bin/bash
g++ cpu_anomaly_detect.cpp -o cpu_anomaly_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
