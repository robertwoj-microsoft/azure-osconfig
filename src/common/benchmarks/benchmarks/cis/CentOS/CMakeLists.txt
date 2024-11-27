cmake_minimum_required(VERSION 3.2)

add_subdirectory(7)
add_subdirectory(8)

add_library(benchmarks_cis_CentOS STATIC CentOS.c)

target_link_libraries(benchmarks_cis_CentOS PUBLIC
    logging
    benchmarks_cis_CentOS_7
    benchmarks_cis_CentOS_8
)
