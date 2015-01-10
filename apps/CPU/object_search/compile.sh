#!/bin/bash
g++ cpu_object_search.cpp -o cpu_object_search `pkg-config --cflags --libs opencv` -L/home/ideal/tools/cuda-6.5/lib64
