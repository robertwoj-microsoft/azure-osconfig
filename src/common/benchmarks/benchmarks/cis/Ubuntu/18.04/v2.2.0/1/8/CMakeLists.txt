cmake_minimum_required(VERSION 3.2)

add_subdirectory(10)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8 STATIC Ubuntu_18.04_v2.2.0_1_8.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_10
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_2
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_3
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_4
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_5
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_6
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_7
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_8
    benchmarks_cis_Ubuntu_18_04_v2_2_0_1_8_9
)
