cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Oracle_9_v2_0_0_4_2 STATIC Oracle_9_v2.0.0_4_2.c)

target_link_libraries(benchmarks_cis_Oracle_9_v2_0_0_4_2 PUBLIC
    logging
    benchmarks_cis_Oracle_9_v2_0_0_4_2_1
    benchmarks_cis_Oracle_9_v2_0_0_4_2_2
)
