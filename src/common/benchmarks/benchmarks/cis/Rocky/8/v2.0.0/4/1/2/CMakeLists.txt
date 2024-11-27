cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Rocky_8_v2_0_0_4_1_2 STATIC Rocky_8_v2.0.0_4_1_2.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_4_1_2 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0_4_1_2_1
)
