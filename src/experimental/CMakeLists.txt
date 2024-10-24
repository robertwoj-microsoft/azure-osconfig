cmake_minimum_required(VERSION 3.10)

# Set the project name
# project(experimental)

# Add subdirectory for fs-tests
add_subdirectory(fs-sandbox)
add_subdirectory(fs-tests)
add_subdirectory(fs-watcher)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_C_COMPILER_ID STREQUAL "Clang")
    add_subdirectory(fs-fuzzer)
endif()
