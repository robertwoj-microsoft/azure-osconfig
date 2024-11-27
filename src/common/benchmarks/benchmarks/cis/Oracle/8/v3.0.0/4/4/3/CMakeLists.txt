cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Oracle_8_v3_0_0_4_4_3 STATIC Oracle_8_v3.0.0_4_4_3.c)

target_link_libraries(benchmarks_cis_Oracle_8_v3_0_0_4_4_3 PUBLIC
    logging
    benchmarks_cis_Oracle_8_v3_0_0_4_4_3_1
    benchmarks_cis_Oracle_8_v3_0_0_4_4_3_2
    benchmarks_cis_Oracle_8_v3_0_0_4_4_3_3
    benchmarks_cis_Oracle_8_v3_0_0_4_4_3_4
)
