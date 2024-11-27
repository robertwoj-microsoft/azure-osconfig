cmake_minimum_required(VERSION 3.2)

add_subdirectory(4)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2 STATIC Ubuntu_18.04_v2.2.0_5_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_5_2_4
)
