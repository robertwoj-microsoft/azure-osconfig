cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(3)

add_library(benchmarks_cis_Oracle_8_v3_0_0_5 STATIC Oracle_8_v3.0.0_5.c)

target_link_libraries(benchmarks_cis_Oracle_8_v3_0_0_5 PUBLIC
    logging
    benchmarks_cis_Oracle_8_v3_0_0_5_1
    benchmarks_cis_Oracle_8_v3_0_0_5_3
)
