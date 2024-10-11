cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-tests VERSION 1.0)

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
    main.cpp
)

include(CTest)
find_package(GTest REQUIRED)

# Add the executable
add_executable(fs-tests ${SOURCES} ${HEADERS})

target_link_libraries(fs-tests PRIVATE commonutils logging mpiclient parsonlib asb gtest gtest_main pthread securitybaselinelib logging commonutils)
