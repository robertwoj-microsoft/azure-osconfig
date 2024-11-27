cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_2_4 STATIC Ubuntu_24.04_v1.0.0_1_1_2_4.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_2_4 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_2_4_2
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_2_4_3
)
