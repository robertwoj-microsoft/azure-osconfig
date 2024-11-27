cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_8 STATIC Ubuntu_18.04_v2.2.0_1_1_8.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_8 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_8_1
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_8_2
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_1_8_3
)
