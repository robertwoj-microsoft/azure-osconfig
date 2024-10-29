cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(fs-tests VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
)

set(SOURCES
    main.cpp
)

include(CTest)
find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/experimental/fs-sandbox)

# Add the executable
add_executable(fs-tests ${SOURCES} ${HEADERS})
target_link_libraries(fs-tests PRIVATE fs-sandbox commonutils logging mpiclient parsonlib asb gtest gtest_main pthread securitybaselinelib logging commonutils)
