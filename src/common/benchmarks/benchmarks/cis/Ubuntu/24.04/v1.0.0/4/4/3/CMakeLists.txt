cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3 STATIC Ubuntu_24.04_v1.0.0_4_4_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3_1
    benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3_2
    benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3_3
    benchmarks_cis_Ubuntu_24_04_v1_0_0_4_4_3_4
)
