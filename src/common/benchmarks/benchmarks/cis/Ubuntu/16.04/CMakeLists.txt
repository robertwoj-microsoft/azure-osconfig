cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Ubuntu_16_04 STATIC Ubuntu_16.04.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0
)
