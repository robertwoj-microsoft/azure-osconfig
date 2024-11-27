cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Oracle_9_v2_0_0_1_1_2_6 STATIC Oracle_9_v2.0.0_1_1_2_6.c)

target_link_libraries(benchmarks_cis_Oracle_9_v2_0_0_1_1_2_6 PUBLIC
    logging
    benchmarks_cis_Oracle_9_v2_0_0_1_1_2_6_2
    benchmarks_cis_Oracle_9_v2_0_0_1_1_2_6_3
    benchmarks_cis_Oracle_9_v2_0_0_1_1_2_6_4
)
