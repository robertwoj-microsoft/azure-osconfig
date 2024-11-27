cmake_minimum_required(VERSION 3.2)

add_subdirectory(v4.0.0)

add_library(benchmarks_cis_CentOS_7 STATIC CentOS_7.c)

target_link_libraries(benchmarks_cis_CentOS_7 PUBLIC
    logging
    benchmarks_cis_CentOS_7_v4_0_0
)
