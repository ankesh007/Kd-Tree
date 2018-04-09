#!/bin/bash
# make
g++ -std=c++14 KdTree.cpp main.cpp query.cpp -o KdTree -O3
./KdTree $1