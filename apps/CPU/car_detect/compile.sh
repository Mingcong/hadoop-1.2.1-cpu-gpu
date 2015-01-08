#!/bin/bash
g++ cpu_car_detect.cpp -o cpu_car_detect `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
