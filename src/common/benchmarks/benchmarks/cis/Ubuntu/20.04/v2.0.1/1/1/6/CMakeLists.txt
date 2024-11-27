cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6 STATIC Ubuntu_20.04_v2.0.1_1_1_6.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_2
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_3
    benchmarks_cis_Ubuntu_20_04_v2_0_1_1_1_6_4
)
