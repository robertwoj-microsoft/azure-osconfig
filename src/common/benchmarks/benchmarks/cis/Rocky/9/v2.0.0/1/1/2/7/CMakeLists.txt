cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Rocky_9_v2_0_0_1_1_2_7 STATIC Rocky_9_v2.0.0_1_1_2_7.c)

target_link_libraries(benchmarks_cis_Rocky_9_v2_0_0_1_1_2_7 PUBLIC
    logging
    benchmarks_cis_Rocky_9_v2_0_0_1_1_2_7_2
    benchmarks_cis_Rocky_9_v2_0_0_1_1_2_7_3
    benchmarks_cis_Rocky_9_v2_0_0_1_1_2_7_4
)
