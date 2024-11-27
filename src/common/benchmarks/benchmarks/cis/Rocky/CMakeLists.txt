cmake_minimum_required(VERSION 3.2)

add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Rocky STATIC Rocky.c)

target_link_libraries(benchmarks_cis_Rocky PUBLIC
    logging
    benchmarks_cis_Rocky_8
    benchmarks_cis_Rocky_9
)
