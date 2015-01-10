#!/bin/bash
g++ gpu_object_search.cpp -o gpu_object_search `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
