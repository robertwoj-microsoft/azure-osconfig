cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_Oracle_9_v2_0_0_1_6 STATIC Oracle_9_v2.0.0_1_6.c)

target_link_libraries(benchmarks_cis_Oracle_9_v2_0_0_1_6 PUBLIC
    logging
    benchmarks_cis_Oracle_9_v2_0_0_1_6_1
    benchmarks_cis_Oracle_9_v2_0_0_1_6_2
    benchmarks_cis_Oracle_9_v2_0_0_1_6_3
    benchmarks_cis_Oracle_9_v2_0_0_1_6_4
    benchmarks_cis_Oracle_9_v2_0_0_1_6_5
    benchmarks_cis_Oracle_9_v2_0_0_1_6_6
    benchmarks_cis_Oracle_9_v2_0_0_1_6_7
)
