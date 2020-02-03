#!/bin/bash
set -e

if [ ! -d "build" ]; then
    mkdir build
fi

cd build
cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release ..
make -j8
