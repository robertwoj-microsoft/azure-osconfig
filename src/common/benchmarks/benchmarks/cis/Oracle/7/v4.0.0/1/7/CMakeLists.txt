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

add_library(benchmarks_cis_Oracle_7_v4_0_0_1_7 STATIC Oracle_7_v4.0.0_1_7.c)

target_link_libraries(benchmarks_cis_Oracle_7_v4_0_0_1_7 PUBLIC
    logging
    benchmarks_cis_Oracle_7_v4_0_0_1_7_10
    benchmarks_cis_Oracle_7_v4_0_0_1_7_2
    benchmarks_cis_Oracle_7_v4_0_0_1_7_3
    benchmarks_cis_Oracle_7_v4_0_0_1_7_4
    benchmarks_cis_Oracle_7_v4_0_0_1_7_5
    benchmarks_cis_Oracle_7_v4_0_0_1_7_6
    benchmarks_cis_Oracle_7_v4_0_0_1_7_7
    benchmarks_cis_Oracle_7_v4_0_0_1_7_8
    benchmarks_cis_Oracle_7_v4_0_0_1_7_9
)
