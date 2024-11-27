cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6 STATIC Ubuntu_16.04_v2.0.0_1_6.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_6_1
)
