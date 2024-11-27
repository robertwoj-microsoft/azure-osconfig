cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(18)
add_subdirectory(19)
add_subdirectory(2)
add_subdirectory(20)
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(23)
add_subdirectory(24)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1 STATIC Ubuntu_16.04_v2.0.0_1_1.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_1
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_12
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_13
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_14
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_18
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_19
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_2
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_20
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_21
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_22
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_23
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_24
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_3
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_4
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_5
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_6
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_7
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_8
    benchmarks_cis_Ubuntu_16_04_v2_0_0_1_1_9
)
