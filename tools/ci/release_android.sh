#!/bin/bash

set -ex

RELEASE_HOME=$(cd $(dirname $0)/../..; pwd)
BUILD_DIR=${RELEASE_HOME}/release_android

[[ -d ${BUILD_DIR} ]] && rm -r ${BUILD_DIR}

build() {
    arch=$1
    NDK_API_LEVEL=$2
    mkdir -p ${BUILD_DIR}/${arch}
    pushd ${BUILD_DIR}/${arch}
    cmake ${RELEASE_HOME} \
        -G "Unix Makefiles" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_TOOLCHAIN_FILE=${ANDROID_NDK}/build/cmake/android.toolchain.cmake \
        -DANDROID_TOOLCHAIN=clang \
        -DWITH_SNPE=ON \
        -DANDROID_ABI=${arch} \
        -DANDROID_NATIVE_API_LEVEL=${NDK_API_LEVEL} \
        -DANDROID_STL=c++_static 
    make -j4
    popd
}


build arm64-v8a 31
#build arm64-v8a 24
#build arm64-v8a 21
#build armeabi-v7a 21
