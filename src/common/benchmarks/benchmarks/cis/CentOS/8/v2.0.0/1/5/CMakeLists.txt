cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_CentOS_8_v2_0_0_1_5 STATIC CentOS_8_v2.0.0_1_5.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_1_5 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_1_5_1
    benchmarks_cis_CentOS_8_v2_0_0_1_5_2
    benchmarks_cis_CentOS_8_v2_0_0_1_5_3
)
