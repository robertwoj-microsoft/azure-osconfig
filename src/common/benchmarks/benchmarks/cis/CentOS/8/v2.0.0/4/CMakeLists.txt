cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_CentOS_8_v2_0_0_4 STATIC CentOS_8_v2.0.0_4.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_4 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_4_2
    benchmarks_cis_CentOS_8_v2_0_0_4_3
)
