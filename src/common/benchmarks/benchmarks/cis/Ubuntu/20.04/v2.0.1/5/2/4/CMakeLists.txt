cmake_minimum_required(VERSION 3.2)

add_subdirectory(11)

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4 STATIC Ubuntu_20.04_v2.0.1_5_2_4.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1_5_2_4_11
)
