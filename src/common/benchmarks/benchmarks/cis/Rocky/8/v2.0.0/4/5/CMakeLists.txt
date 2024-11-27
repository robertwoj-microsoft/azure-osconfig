cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Rocky_8_v2_0_0_4_5 STATIC Rocky_8_v2.0.0_4_5.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_4_5 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0_4_5_1
    benchmarks_cis_Rocky_8_v2_0_0_4_5_2
    benchmarks_cis_Rocky_8_v2_0_0_4_5_3
)
