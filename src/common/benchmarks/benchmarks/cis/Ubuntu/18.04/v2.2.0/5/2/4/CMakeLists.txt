cmake_minimum_required(VERSION 3.2)

add_subdirectory(11)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2_4 STATIC Ubuntu_18.04_v2.2.0_5_2_4.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2_4 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2_4_11
)
