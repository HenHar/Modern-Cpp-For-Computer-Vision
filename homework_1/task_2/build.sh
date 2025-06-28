#!/usr/bin/env bash

mkdir build
mkdir results
g++ -c -I include/ src/sum.cpp -o build/sum.o
g++ -c -I include/ src/subtract.cpp -o build/subtract.o


ar rcs build/libipb_arithemtic.a build/sum.o build/subtract.o

g++ src/main.cpp -I include/ -L build/ -l ipb_arithemtic -o results/main
