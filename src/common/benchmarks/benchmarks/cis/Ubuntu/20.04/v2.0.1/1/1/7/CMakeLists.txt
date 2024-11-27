cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_7 STATIC Ubuntu_20.04_v2.0.1_1_1_7.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_7 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_7_2
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_7_3
)
