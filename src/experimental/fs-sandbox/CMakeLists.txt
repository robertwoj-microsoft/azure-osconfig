cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-sandbox VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
    tempdir.hpp
    sandbox.hpp
    container.hpp
    mountpoint.hpp
)

set(SOURCES
    tempdir.cpp
    sandbox.cpp
    container.cpp
    mountpoint.cpp
)

# Add the executable
add_library(fs-sandbox ${SOURCES} ${HEADERS})
