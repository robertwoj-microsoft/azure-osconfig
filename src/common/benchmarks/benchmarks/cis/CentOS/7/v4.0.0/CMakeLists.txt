cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_CentOS_7_v4_0_0 STATIC CentOS_7_v4.0.0.c)

target_link_libraries(benchmarks_cis_CentOS_7_v4_0_0 PUBLIC
    logging
    benchmarks_cis_CentOS_7_v4_0_0_1
    benchmarks_cis_CentOS_7_v4_0_0_2
    benchmarks_cis_CentOS_7_v4_0_0_3
    benchmarks_cis_CentOS_7_v4_0_0_4
    benchmarks_cis_CentOS_7_v4_0_0_5
    benchmarks_cis_CentOS_7_v4_0_0_6
)
