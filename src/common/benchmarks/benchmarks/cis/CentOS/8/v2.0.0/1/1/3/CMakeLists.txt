cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_CentOS_8_v2_0_0_1_1_3 STATIC CentOS_8_v2.0.0_1_1_3.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_1_1_3 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_1_1_3_2
    benchmarks_cis_CentOS_8_v2_0_0_1_1_3_3
    benchmarks_cis_CentOS_8_v2_0_0_1_1_3_4
)
