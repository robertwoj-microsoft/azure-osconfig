cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_1 STATIC Ubuntu_18.04_v2.2.0_2_1_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_1_1
)
