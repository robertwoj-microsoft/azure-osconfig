cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 STATIC Ubuntu_24.04_v1.0.0_6_1_4.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4_1
)
