cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Oracle_9 STATIC Oracle_9.c)

target_link_libraries(benchmarks_cis_Oracle_9 PUBLIC
    logging
    benchmarks_cis_Oracle_9_v2_0_0
)
