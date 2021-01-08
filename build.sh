#!/bin/bash
#compile from CMake

# cd Src/twitcurl/libtwitcurl
# make
# cd ../../..

if [ -d "build" ]; then
rm -r build
fi

mkdir build
cd build
cmake ..

cd build/
make