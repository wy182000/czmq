#!/usr/bin/env bash

set -x
set -e

########################################################################
# Build and check the jni binding
########################################################################

BUILD_PREFIX=/tmp

CONFIG_OPTS=()
CONFIG_OPTS+=("CFLAGS=-I${BUILD_PREFIX}/include")
CONFIG_OPTS+=("CPPFLAGS=-I${BUILD_PREFIX}/include")
CONFIG_OPTS+=("CXXFLAGS=-I${BUILD_PREFIX}/include")
CONFIG_OPTS+=("LDFLAGS=-L${BUILD_PREFIX}/lib")
CONFIG_OPTS+=("PKG_CONFIG_PATH=${BUILD_PREFIX}/lib/pkgconfig")
CONFIG_OPTS+=("--prefix=${BUILD_PREFIX}")
CONFIG_OPTS+=("--with-docs=no")
CONFIG_OPTS+=("--quiet")

pushd ../../..

# Clone and build dependencies
git clone --quiet --depth 1 https://github.com/zeromq/libzmq.git libzmq
cd libzmq
git --no-pager log --oneline -n1
if [ -e autogen.sh ]; then
    ./autogen.sh 2> /dev/null
fi
if [ -e buildconf ]; then
    ./buildconf 2> /dev/null
fi
if [ ! -e autogen.sh ] && [ ! -e buildconf ] && [ ! -e ./configure ] && [ -s ./configure.ac ]; then
    libtoolize --copy --force && \
    aclocal -I . && \
    autoheader && \
    automake --add-missing --copy && \
    autoconf || \
    autoreconf -fiv
fi
./configure "${CONFIG_OPTS[@]}"
make -j4
make install
cd ..

popd
pushd ../..

./autogen.sh 2> /dev/null
./configure "${CONFIG_OPTS[@]}"
make -j4
make install

popd

TERM=dumb PKG_CONFIG_PATH=$BUILD_PREFIX/lib/pkgconfig ./gradlew build jar
TERM=dumb ./gradlew clean

########################################################################
#  Build and check the jni android binding
########################################################################

pushd ../../builds/android

. ./ci_build.sh

popd

pushd android

TERM=dumb PKG_CONFIG_PATH=$BUILD_PREFIX/lib/pkgconfig ./build.sh

popd
