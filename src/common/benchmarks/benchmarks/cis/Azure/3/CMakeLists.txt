cmake_minimum_required(VERSION 3.2)

add_subdirectory(v1.0.0)

add_library(benchmarks_cis_Azure_3 STATIC Azure_3.c)

target_link_libraries(benchmarks_cis_Azure_3 PUBLIC
    logging
    benchmarks_cis_Azure_3_v1_0_0
)
