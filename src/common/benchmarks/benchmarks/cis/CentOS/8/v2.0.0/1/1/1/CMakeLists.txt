cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_CentOS_8_v2_0_0_1_1_1 STATIC CentOS_8_v2.0.0_1_1_1.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_1_1_1 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_1_1_1_1
)
