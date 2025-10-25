#!/usr/bin/env bash
mkdir -p build && cd build
cmake -S .. -B . -G Ninja
cmake --build . -j
./main