cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Azure_3_v1_0_0_5_4 STATIC Azure_3_v1.0.0_5_4.c)

target_link_libraries(benchmarks_cis_Azure_3_v1_0_0_5_4 PUBLIC
    logging
    benchmarks_cis_Azure_3_v1_0_0_5_4_1
    benchmarks_cis_Azure_3_v1_0_0_5_4_2
    benchmarks_cis_Azure_3_v1_0_0_5_4_3
    benchmarks_cis_Azure_3_v1_0_0_5_4_4
)
