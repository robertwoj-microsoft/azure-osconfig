cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3 STATIC Ubuntu_22.04_v2.0.0_2_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3 PUBLIC
    logging
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_1
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_2
    benchmarks_cis_Ubuntu_22_04_v2_0_0_2_3_3
)
