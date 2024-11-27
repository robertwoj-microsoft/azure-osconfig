cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Oracle_7_v4_0_0_4_1_2 STATIC Oracle_7_v4.0.0_4_1_2.c)

target_link_libraries(benchmarks_cis_Oracle_7_v4_0_0_4_1_2 PUBLIC
    logging
    benchmarks_cis_Oracle_7_v4_0_0_4_1_2_1
)
