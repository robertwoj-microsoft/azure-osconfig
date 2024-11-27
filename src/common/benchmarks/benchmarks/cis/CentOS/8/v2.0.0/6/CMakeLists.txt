cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_CentOS_8_v2_0_0_6 STATIC CentOS_8_v2.0.0_6.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_6 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_6_1
    benchmarks_cis_CentOS_8_v2_0_0_6_2
)
