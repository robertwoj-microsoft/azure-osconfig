#!/bin/bash
# PS4='+${LINENO}: '
# set -x
set -eou pipefail

sources_path="/sources"
build_path="/build"

function die
{
	echo "ERROR: $1"
	exit 1
}

if [ ! -d ${sources_path} ]; then
	die "Missing ${sources_path} directory"
fi

if [ ! -d ${build_path} ]; then
	die "Missing ${build_path} directory"
fi

cd ${build_path}
cmake \
	-DBUILD_EXPERIMENTAL=ON \
	-DCMAKE_C_COMPILER=/usr/bin/clang-15 \
	-DCMAKE_CXX_COMPILER=/usr/bin/clang++-15 \
	-DCMAKE_C_FLAGS="-fsanitize=fuzzer-no-link,address,undefined -g -O1 -fno-omit-frame-pointer" \
	-DCMAKE_CXX_FLAGS="-fsanitize=fuzzer-no-link,address,undefined -g -O1 -fno-omit-frame-pointer" \
	${sources_path}/src \
	|| die "Failed to run cmake"

cmake --build .