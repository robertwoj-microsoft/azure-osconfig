cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)

add_library(benchmarks_cis_Rocky_8_v2_0_0_2_3 STATIC Rocky_8_v2.0.0_2_3.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_2_3 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0_2_3_1
    benchmarks_cis_Rocky_8_v2_0_0_2_3_3
    benchmarks_cis_Rocky_8_v2_0_0_2_3_4
    benchmarks_cis_Rocky_8_v2_0_0_2_3_5
)
