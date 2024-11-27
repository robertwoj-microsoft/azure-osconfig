cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.2.0)

add_library(benchmarks_cis_Ubuntu_18_04 STATIC Ubuntu_18.04.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0
)
