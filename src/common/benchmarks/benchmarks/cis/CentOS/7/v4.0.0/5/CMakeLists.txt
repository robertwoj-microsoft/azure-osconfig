cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(3)

add_library(benchmarks_cis_CentOS_7_v4_0_0_5 STATIC CentOS_7_v4.0.0_5.c)

target_link_libraries(benchmarks_cis_CentOS_7_v4_0_0_5 PUBLIC
    logging
    benchmarks_cis_CentOS_7_v4_0_0_5_1
    benchmarks_cis_CentOS_7_v4_0_0_5_3
)
