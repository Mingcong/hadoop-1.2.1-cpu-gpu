#!/bin/bash
g++ cpu_pedestrian_detect.cpp -o cpu_pedestrian_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
