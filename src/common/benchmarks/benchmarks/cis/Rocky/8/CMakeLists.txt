cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Rocky_8 STATIC Rocky_8.c)

target_link_libraries(benchmarks_cis_Rocky_8 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0
)
