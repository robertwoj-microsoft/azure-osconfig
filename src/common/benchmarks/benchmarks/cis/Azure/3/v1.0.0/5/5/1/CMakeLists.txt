cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)

add_library(benchmarks_cis_Azure_3_v1_0_0_5_5_1 STATIC Azure_3_v1.0.0_5_5_1.c)

target_link_libraries(benchmarks_cis_Azure_3_v1_0_0_5_5_1 PUBLIC
    logging
    benchmarks_cis_Azure_3_v1_0_0_5_5_1_1
    benchmarks_cis_Azure_3_v1_0_0_5_5_1_2
    benchmarks_cis_Azure_3_v1_0_0_5_5_1_3
    benchmarks_cis_Azure_3_v1_0_0_5_5_1_4
    benchmarks_cis_Azure_3_v1_0_0_5_5_1_5
)
