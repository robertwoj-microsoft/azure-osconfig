cmake_minimum_required(VERSION 3.2)

add_subdirectory(3)

add_library(benchmarks_cis_Azure STATIC Azure.c)

target_link_libraries(benchmarks_cis_Azure PUBLIC
    logging
    benchmarks_cis_Azure_3
)
