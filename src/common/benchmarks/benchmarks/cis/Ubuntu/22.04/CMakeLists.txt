cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Ubuntu_22_04 STATIC Ubuntu_22.04.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04 PUBLIC
    logging
    benchmarks_cis_Ubuntu_22_04_v2_0_0
)
