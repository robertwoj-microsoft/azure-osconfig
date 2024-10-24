#!/bin/bash
set -euo pipefail
PROGNAME=$0
usage() {
	cat <<EOF
	${PROGNAME} -d dir -k dir -o dir [-h]"
	            -d|dir_mof_base_resource directory of mgmt guestconfig gcagent
			should contan OMI_BaseResource.mof and MSFT_Credential.mof
		    -k|windows_kit_dir dir
			directory for windows kit usually /mnt/c/Program Files (x86)/Windows Kits/10/bin
		    -o|out_dir dir where generated files will be written to
		    -h|help prints this help
EOF
}
die() {
	usage
	exit $1
}
while getopts ":d:k:o:h:-" opt ; do
	case ${opt} in
	h|help) die 0 ;;
	d|dir_mof_base_resource)
		DIR_MOF_BASE_RESOURCE=${OPTARG}
	;;
	k|windows_kit_dir)
		WINDOWS_KIT_BIN_DIR=${OPTARG}
	;;
	o|out_dir)
		OUT_DIR=${OPTARG}
	;;
	-)
		case "${OPTARG}" in
			help)
				die 0
			;;
			dir_mof_base_resource)
				DIR_MOF_BASE_RESOURCE=${OPTARG}
			;;
			windows_kit_dir)
				WINDOWS_KIT_BIN_DIR=${OPTARG}
			;;
			out_dir)
				OUT_DIR=${OPTARG}
			;;
		*)
			echo "Invalid option: --${OPTARG}"
			die 1
			;;

		esac
	;;
	\?)
			echo "Invalid option: --${OPTARG}"
			die 2
			;;
	: )
			echo "Invalid option, option ${OPTARG} requires arument"
			die 3
			;;

	esac

done

set +u
if [[ -z "${WINDOWS_KIT_BIN_DIR}" || -z "${DIR_MOF_BASE_RESOURCE}" || -z "${OUT_DIR}" ]] ; then
	echo "Missing required arguments"
	die 4
fi
set -u
# echo "WIN_KIT_BIN_DIR=" "${WINDOWS_KIT_BIN_DIR}"
# echo "DIR_MOF_BASE_RESOURCE " "${DIR_MOF_BASE_RESOURCE}"


WINDOWS_KIT_ARCH=x64
# possible Windwos Kit architectures are x86, arm64
# WINDOWS_KIT_BIN_DIR="/mnt/c/Program Files (x86)/Windows Kits/10/bin/"
WINDOWS_KIT_LATEST_DIR=$(ls -al "${WINDOWS_KIT_BIN_DIR}"|awk '$9 ~/[0-9]+\.[0-9\.]*/{print $9}' | sort -V |tail -n1)
WINDOWS_KIT_LATEST_PATH="${WINDOWS_KIT_BIN_DIR}/${WINDOWS_KIT_LATEST_DIR}/${WINDOWS_KIT_ARCH}"
# due to space in WINDOWS_KIT_LATEST_PATH always use "${WINDOWS_KIT_LATEST_PATH}" when using in script
if [ ! -d "${WINDOWS_KIT_LATEST_PATH}" ] ; then
	echo 'Unable to use '"${WINDOWS_KIT_LATEST_PATH}"' as windows tools kit'
	exit 1
fi

copy_or_die() {
	file="$*"
	if [ ! -f "${file}" ] ; then
		echo "Missing required file: ${file}"
		die 5
	fi
	cp "${file}" .
}

copy_or_die "${DIR_MOF_BASE_RESOURCE}"/src/dsc/engine/mof/OMI_BaseResource.mof
copy_or_die "${DIR_MOF_BASE_RESOURCE}"/src/dsc/engine/mof/MSFT_Credential.mof

"${WINDOWS_KIT_LATEST_PATH}"/convert-moftoprovider.exe -MofFile OsConfig.schema.mof -ClassList OsConfigResource -IncludePath "${DIR_MOF_BASE_RESOURCE}"/tools/UtilTools/ProviderGenerationTool/CIM-2.26.0 -OutPath "${OUT_DIR}" -NoSAL
