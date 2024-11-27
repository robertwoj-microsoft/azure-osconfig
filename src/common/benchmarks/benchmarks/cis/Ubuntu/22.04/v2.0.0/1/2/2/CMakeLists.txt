cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_22_04_v2_0_0_1_2_2 STATIC Ubuntu_22.04_v2.0.0_1_2_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04_v2_0_0_1_2_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_22_04_v2_0_0_1_2_2_1
)
