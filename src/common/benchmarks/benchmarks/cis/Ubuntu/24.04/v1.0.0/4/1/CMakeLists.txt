cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_1 STATIC Ubuntu_24.04_v1.0.0_4_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_4_1_1
)
