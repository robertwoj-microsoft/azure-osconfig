cmake_minimum_required(VERSION 3.2)

# Set the project name and version
project(osconfig-fuzzer)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(LLVM REQUIRED)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=fuzzer")
# add_library(libfuzzer STATIC IMPORTED)
# set_property(TARGET libfuzzer PROPERTY IMPORTED_LOCATION "${LLVM_LIBRARY_DIR}/clang/${LLVM_VERSION}/lib/linux/libclang_rt.fuzzer_no_main-x86_64.a")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lSegFault")
include_directories(${CMAKE_SOURCE_DIR}/common/commonutils)
add_executable(osconfig-fuzzer target.cpp)
target_link_libraries(osconfig-fuzzer PRIVATE asb)
