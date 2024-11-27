cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7 STATIC Ubuntu_18.04_v2.2.0_1_7.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_1
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_2
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_3
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_4
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_5
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_7_6
)
