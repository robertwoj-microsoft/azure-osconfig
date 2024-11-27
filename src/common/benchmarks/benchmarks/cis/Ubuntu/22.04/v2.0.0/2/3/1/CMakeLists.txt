cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_1 STATIC Ubuntu_22.04_v2.0.0_2_3_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_1_1
)
