#!/bin/bash
g++ gpu_car_detect.cpp -o gpu_car_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
