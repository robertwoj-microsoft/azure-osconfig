# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# CIS for Linux
project(OsConfigResourceCIS)

add_library(OsConfigResourceCIS
    SHARED
        ../module.c
        ../schema.c
        ../OsConfigResource.c)

target_link_libraries(OsConfigResourceCIS
    PRIVATE
        commonutils
        logging
        mpiclient
        parsonlib
        asb
        benchmarks)

# SO binary name must match the universal class name in MOF with a "lib" prefix added
set_target_properties(OsConfigResourceCIS PROPERTIES OUTPUT_NAME libOsConfigResource)

# Create the policy artifacts ZIP package for CIS benchmarks
add_custom_target(stage_create_cis_zip
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/Staging
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/robertwoj_benchmarks.metaconfig.json" ${PROJECT_BINARY_DIR}/Staging/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/robertwoj_benchmarks.mof" ${PROJECT_BINARY_DIR}/Staging/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/pre_install.sh" ${PROJECT_BINARY_DIR}/Staging/
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/common/benchmarks/mof" ${PROJECT_BINARY_DIR}/Staging/Modules/DscNativeResources/OsConfigResource/Definitions/benchmarks
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:OsConfigResourceCIS> ${PROJECT_BINARY_DIR}/Staging/Modules/DscNativeResources/OsConfigResource/libOsConfigResource.so
    DEPENDS OsConfigResourceCIS)

add_custom_target(create_cis_zip ALL
    BYPRODUCTS ${OsConfigRootBinaryDir}/robertwoj_benchmarks.zip
    COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${OsConfigRootBinaryDir}/robertwoj_benchmarks.zip" --format=zip .
    DEPENDS stage_create_cis_zip
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/Staging/)