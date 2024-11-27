cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)

add_library(benchmarks_cis_Rocky_8_v2_0_0_1_5_1 STATIC Rocky_8_v2.0.0_1_5_1.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_1_5_1 PUBLIC
    logging
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_1
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_2
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_3
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_4
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_6
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_7
    benchmarks_cis_Rocky_8_v2_0_0_1_5_1_8
)
