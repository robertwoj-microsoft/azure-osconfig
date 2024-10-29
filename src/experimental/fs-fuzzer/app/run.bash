#!/bin/bash
# PS4='+${LINENO}: '
# set -x
set -eou pipefail

build_path="/build"
corpus_path="/corpus"

function die
{
	echo "ERROR: $1"
	exit 1
}

if [ ! -d ${build_path} ]; then
	die "Missing ${build_path} directory"
fi

if [ ! -d ${corpus_path} ]; then
	die "Missing ${corpus_path} directory"
fi

cd ${corpus_path}
ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer-15 ${build_path}/experimental/fs-fuzzer/fs-fuzzer -use_value_profile=0 ${corpus_path} > /dev/null
