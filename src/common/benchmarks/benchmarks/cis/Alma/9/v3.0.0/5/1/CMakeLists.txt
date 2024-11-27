cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
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
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Alma_9_v3_0_0_5_1 STATIC Alma_9_v3.0.0_5_1.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_5_1 PUBLIC
    logging
    benchmarks_cis_Alma_9_v3_0_0_5_1_1
    benchmarks_cis_Alma_9_v3_0_0_5_1_12
    benchmarks_cis_Alma_9_v3_0_0_5_1_13
    benchmarks_cis_Alma_9_v3_0_0_5_1_14
    benchmarks_cis_Alma_9_v3_0_0_5_1_15
    benchmarks_cis_Alma_9_v3_0_0_5_1_16
    benchmarks_cis_Alma_9_v3_0_0_5_1_17
    benchmarks_cis_Alma_9_v3_0_0_5_1_18
    benchmarks_cis_Alma_9_v3_0_0_5_1_19
    benchmarks_cis_Alma_9_v3_0_0_5_1_2
    benchmarks_cis_Alma_9_v3_0_0_5_1_20
    benchmarks_cis_Alma_9_v3_0_0_5_1_21
    benchmarks_cis_Alma_9_v3_0_0_5_1_22
    benchmarks_cis_Alma_9_v3_0_0_5_1_3
    benchmarks_cis_Alma_9_v3_0_0_5_1_4
    benchmarks_cis_Alma_9_v3_0_0_5_1_5
    benchmarks_cis_Alma_9_v3_0_0_5_1_6
    benchmarks_cis_Alma_9_v3_0_0_5_1_7
    benchmarks_cis_Alma_9_v3_0_0_5_1_8
    benchmarks_cis_Alma_9_v3_0_0_5_1_9
)
