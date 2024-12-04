#!/bin/bash

# This script is executed before the installation of the package

set -eou pipefail

if [ $# -ne 1 ]; then
    echo "Error: Input must contain exactly one argument."
    exit 1
fi

script_path=$(dirname "$(realpath "$0")")
array=(${1//@pid/ })
if [ ${#array[@]} -ne 2 ]; then
    echo "Error: Input must contain exactly one '@pid' separator."
    exit 1
fi

policy_name=${array[0]}
definition_name=${array[1]//_/.}
definition_path=${array[1]//_//}
echo "Policy name: ${policy_name}"
echo "Benchmark name: ${definition_name}"
echo "Benchmark path: ${definition_path}"

if [ ! -f "${script_path}/${policy_name}.mof" ]; then
    echo "Error: ${script_path}/${policy_name}.mof does not exist"
    exit 1
fi

definitions_path="${script_path}/Modules/DscNativeResources/OsConfigResource/Definitions/benchmarks/${definition_path}/${definition_name}.mof"
if [ ! -f "${definitions_path}" ]; then
    echo "Error: Definition file ${definitions_path} does not exist."
    exit 1
fi

cp -v "${definitions_path}" "${script_path}/${policy_name}.mof"
