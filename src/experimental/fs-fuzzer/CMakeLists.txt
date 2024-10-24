cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-fuzzer VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
)

set(SOURCES
    fs-target.cpp
)

find_package(LibArchive REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=fuzzer")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=fuzzer")

include_directories(${CMAKE_SOURCE_DIR}/experimental/fs-sandbox)

# Add the executable
add_executable(fs-fuzzer fs-target.cpp)
target_link_libraries(fs-fuzzer PRIVATE fs-sandbox mpiclient asb pthread securitybaselinelib ${LibArchive_LIBRARIES})

add_executable(payload-fuzzer payload-target.cpp)
target_link_libraries(payload-fuzzer PRIVATE fs-sandbox mpiclient asb pthread securitybaselinelib)
