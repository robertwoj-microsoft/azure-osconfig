cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(15)
add_subdirectory(16)
add_subdirectory(17)
add_subdirectory(18)
add_subdirectory(19)
add_subdirectory(2)
add_subdirectory(20)
add_subdirectory(22)
add_subdirectory(23)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3 STATIC Ubuntu_16.04_v2.0.0_5_3.c)

target_link_libraries(benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3 PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_1
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_10
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_11
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_12
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_13
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_14
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_15
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_16
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_17
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_18
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_19
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_2
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_20
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_22
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_23
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_3
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_4
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_5
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_6
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_8
    benchmarks_cis_Ubuntu_16_04_v2_0_0_5_3_9
)
