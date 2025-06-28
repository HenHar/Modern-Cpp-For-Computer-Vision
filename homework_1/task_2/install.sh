#!/bin/sh

rm -rf install
mkdir install
rm -rf build
mkdir build
cd build
cmake ..
make
make install

