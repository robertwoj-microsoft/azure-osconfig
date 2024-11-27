cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_2 STATIC Ubuntu_20.04_v2.0.1_1_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_2_1
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_2_2
)
