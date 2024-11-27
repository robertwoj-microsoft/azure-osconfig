cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_CentOS_8_v2_0_0_5_3 STATIC CentOS_8_v2.0.0_5_3.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_5_3 PUBLIC
    logging
    benchmarks_cis_CentOS_8_v2_0_0_5_3_1
    benchmarks_cis_CentOS_8_v2_0_0_5_3_2
    benchmarks_cis_CentOS_8_v2_0_0_5_3_3
    benchmarks_cis_CentOS_8_v2_0_0_5_3_5
    benchmarks_cis_CentOS_8_v2_0_0_5_3_6
    benchmarks_cis_CentOS_8_v2_0_0_5_3_7
)
