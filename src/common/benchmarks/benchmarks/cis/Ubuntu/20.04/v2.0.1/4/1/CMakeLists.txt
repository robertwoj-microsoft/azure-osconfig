cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1 STATIC Ubuntu_20.04_v2.0.1_4_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_1
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_2
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_3
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_4
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_5
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_6
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_7
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_8
    benchmarks_cis_Ubuntu_20_04_v2_0_1_4_1_9
)
