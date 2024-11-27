cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)

add_library(benchmarks_cis_CentOS_8_v2_0_0_5_6 STATIC CentOS_8_v2.0.0_5_6.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_5_6 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_5_6_1
    benchmarks_cis_CentOS_8_v2_0_0_5_6_2
    benchmarks_cis_CentOS_8_v2_0_0_5_6_3
    benchmarks_cis_CentOS_8_v2_0_0_5_6_4
    benchmarks_cis_CentOS_8_v2_0_0_5_6_5
)
