# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# CIS for Linux
project(OsConfigResourceMachineDetection)

add_library(OsConfigResourceMachineDetection
    SHARED
        ../module.c
        ../schema.c
        ../OsConfigResource.c)

target_link_libraries(OsConfigResourceMachineDetection
    PRIVATE
        commonutils
        logging
        mpiclient
        parsonlib
        asb
        benchmarks)

# SO binary name must match the universal class name in MOF with a "lib" prefix added
set_target_properties(OsConfigResourceMachineDetection PROPERTIES OUTPUT_NAME libOsConfigResource)

# Create the policy artifacts ZIP package for CIS benchmarks

add_custom_target(stage_create_machine_detection_zip
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/Staging
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/machine-detection.metaconfig.json" ${PROJECT_BINARY_DIR}/Staging/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/machine-detection.mof" ${PROJECT_BINARY_DIR}/Staging/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:OsConfigResourceMachineDetection> ${PROJECT_BINARY_DIR}/Staging/Modules/DscNativeResources/OsConfigResource/libOsConfigResource.so
    DEPENDS OsConfigResourceMachineDetection)

add_custom_target(create_machine_detection_zip ALL
    BYPRODUCTS ${OsConfigRootBinaryDir}/machine-detection.zip
    COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${OsConfigRootBinaryDir}/machine-detection.zip" --format=zip .
    DEPENDS stage_create_machine_detection_zip
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/Staging/)