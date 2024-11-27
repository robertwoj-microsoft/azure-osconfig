cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(3)

add_library(benchmarks_cis_Rocky_9_v2_0_0_3 STATIC Rocky_9_v2.0.0_3.c)

target_link_libraries(benchmarks_cis_Rocky_9_v2_0_0_3 PUBLIC
    logging
    benchmarks_cis_Rocky_9_v2_0_0_3_1
    benchmarks_cis_Rocky_9_v2_0_0_3_3
)
