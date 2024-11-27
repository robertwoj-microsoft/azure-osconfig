cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.1)

add_library(benchmarks_cis_Ubuntu_20_04 STATIC Ubuntu_20.04.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1
)
