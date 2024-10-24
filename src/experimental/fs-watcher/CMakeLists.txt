cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-watcher VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
)

set(SOURCES
    main.cpp
)

# Find inotify package
# find_package(Inotify REQUIRED)

# Add the executable
add_executable(fs-watcher ${SOURCES} ${HEADERS})
