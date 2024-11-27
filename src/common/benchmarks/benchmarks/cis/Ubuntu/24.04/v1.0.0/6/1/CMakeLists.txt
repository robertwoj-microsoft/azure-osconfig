cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1 STATIC Ubuntu_24.04_v1.0.0_6_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_1
    benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_2
    benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_3
    benchmarks_cis_Ubuntu_24_04_v1_0_0_6_1_4
)
