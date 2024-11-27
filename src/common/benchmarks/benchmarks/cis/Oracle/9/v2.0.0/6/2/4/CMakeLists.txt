cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Oracle_9_v2_0_0_6_2_4 STATIC Oracle_9_v2.0.0_6_2_4.c)

target_link_libraries(benchmarks_cis_Oracle_9_v2_0_0_6_2_4 PUBLIC
    logging
    benchmarks_cis_Oracle_9_v2_0_0_6_2_4_1
)
