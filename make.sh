#!/bin/bash

if [[ "$1" == "clean" ]]; then
    rm -f hypercycles lvldef_builder
    rm -rf build

    echo "Build files deleted"
    exit
fi

set -e

mkdir -p build
cd build

cmake ..

echo -e "\nExecuting: make $1"
make $1

cd ..