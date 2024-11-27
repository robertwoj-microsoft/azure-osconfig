cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_5 STATIC Ubuntu_16.04_v2.0.0_5.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_5 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_1
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_2
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_4
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_5
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_6
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_7
)
