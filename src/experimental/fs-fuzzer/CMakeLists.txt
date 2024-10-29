cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-fuzzer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(LLVM REQUIRED)

set(HEADERS
)

set(SOURCES
    fs-target.cpp
)

find_package(LibArchive REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/experimental/fs-sandbox)

# Add the executable
add_executable(fs-fuzzer fs-target.cpp)
add_library(libfuzzer STATIC IMPORTED)
set_property(TARGET libfuzzer PROPERTY IMPORTED_LOCATION "${LLVM_LIBRARY_DIR}/clang/${LLVM_VERSION}/lib/linux/libclang_rt.fuzzer_no_main-x86_64.a")
target_link_libraries(fs-fuzzer PRIVATE fs-sandbox mpiclient asb pthread securitybaselinelib ${LibArchive_LIBRARIES} libfuzzer)

# add_executable(payload-fuzzer payload-target.cpp)
# target_link_libraries(payload-fuzzer PRIVATE fs-sandbox mpiclient asb pthread securitybaselinelib)
