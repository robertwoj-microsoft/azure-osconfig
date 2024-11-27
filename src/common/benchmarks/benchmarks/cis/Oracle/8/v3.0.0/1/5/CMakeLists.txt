cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Oracle_8_v3_0_0_1_5 STATIC Oracle_8_v3.0.0_1_5.c)

target_link_libraries(benchmarks_cis_Oracle_8_v3_0_0_1_5 PUBLIC
    logging
    benchmarks_cis_Oracle_8_v3_0_0_1_5_1
)
