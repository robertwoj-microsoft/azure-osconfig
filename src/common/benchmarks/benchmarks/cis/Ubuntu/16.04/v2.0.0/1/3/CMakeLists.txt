cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_3 STATIC Ubuntu_16.04_v2.0.0_1_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_3 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_3_1
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_3_2
)
