#!/bin/bash

# replace this with the location of UserC2/include
externPath="../../include/"

externIncludes="${externPath}C2Utility.cpp ${externPath}input.cpp"

source="main.cpp ${externIncludes}"
g++ -std=c++17 -Wall -Werror -I./ -I${externPath} ${source} -O3 -o family
 