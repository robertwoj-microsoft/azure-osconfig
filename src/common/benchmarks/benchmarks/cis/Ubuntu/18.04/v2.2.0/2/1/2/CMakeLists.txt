cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_2 STATIC Ubuntu_18.04_v2.2.0_2_1_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_2_1
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_2_2
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_1_2_3
)
