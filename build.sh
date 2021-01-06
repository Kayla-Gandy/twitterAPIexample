#!/bin/bash
#compile from CMake

if [ -d "build" ]; then
rm -r build
fi

mkdir build
cd build
cmake ..

cd build/
make