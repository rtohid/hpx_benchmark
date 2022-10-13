#!/bin/bash

BUILD_TYPE=Release
HPX_PATH=/work/rod/benchmark/hpx/cmake-build/${BUILD_TYPE}/lib/cmake/HPX

rm -rf cmake-build

cmake -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DHPX_DIR=${HPX_PATH} -DCMAKE_CXX_COMPILER=clang++ -B cmake-build/${BUILD_TYPE} -DCMAKE_CXX_STANDARD=20
cmake --build cmake-build/${BUILD_TYPE} --parallel
