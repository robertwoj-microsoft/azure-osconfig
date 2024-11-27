cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4 STATIC Rocky_9_v2.0.0_5_3_3_4.c)

target_link_libraries(benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4 PUBLIC
    logging
    benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_1
    benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_2
    benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_3
    benchmarks_cis_Rocky_9_v2_0_0_5_3_3_4_4
)
