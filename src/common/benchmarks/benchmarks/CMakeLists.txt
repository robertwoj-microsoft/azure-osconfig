cmake_minimum_required(VERSION 3.2)

add_subdirectory(cis)

add_library(benchmarks STATIC benchmarks.c)

target_link_libraries(benchmarks PUBLIC
    logging
    benchmarks_cis
)
