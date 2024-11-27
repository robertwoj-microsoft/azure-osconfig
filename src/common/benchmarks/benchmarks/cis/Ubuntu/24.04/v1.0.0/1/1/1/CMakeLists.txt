cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(10)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(9)

add_library(benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1 STATIC Ubuntu_24.04_v1.0.0_1_1_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_1
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_10
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_2
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_3
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_4
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_5
    benchmarks_cis_Ubuntu_24_04_v1_0_0_1_1_1_9
)
