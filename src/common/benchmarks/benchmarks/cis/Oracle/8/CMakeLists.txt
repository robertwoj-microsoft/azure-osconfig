cmake_minimum_required(VERSION 3.2)

add_subdirectory(v3.0.0)

add_library(benchmarks_cis_Oracle_8 STATIC Oracle_8.c)

target_link_libraries(benchmarks_cis_Oracle_8 PUBLIC
    logging
    benchmarks_cis_Oracle_8_v3_0_0
)
