cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Azure_3_v1_0_0_4 STATIC Azure_3_v1.0.0_4.c)

target_link_libraries(benchmarks_cis_Azure_3_v1_0_0_4 PUBLIC
    logging
    benchmarks_cis_Azure_3_v1_0_0_4_1
    benchmarks_cis_Azure_3_v1_0_0_4_2
)
