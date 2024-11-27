cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3 STATIC Ubuntu_18.04_v2.2.0_2_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3 PUBLIC
    logging
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_1
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_2
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_3
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_4
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_5
    benchmarks_cis_Ubuntu_18_04_v2_2_0_2_3_6
)
