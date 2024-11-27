cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Rocky_8_v2_0_0_3_4 STATIC Rocky_8_v2.0.0_3_4.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_3_4 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0_3_4_1
    benchmarks_cis_Rocky_8_v2_0_0_3_4_2
)
