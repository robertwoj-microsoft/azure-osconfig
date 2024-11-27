cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_2 STATIC Ubuntu_22.04_v2.0.0_2_3_2.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_2 PUBLIC
    logging
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_2_1
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_2_2
)
