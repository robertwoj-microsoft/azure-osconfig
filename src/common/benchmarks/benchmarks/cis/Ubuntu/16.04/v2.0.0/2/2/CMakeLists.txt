cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2 STATIC Ubuntu_16.04_v2.0.0_2_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_1
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_2
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_3
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_4
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_5
    benchmarks_cis_Ubuntu_16_04_v2_0_0_2_2_6
)
