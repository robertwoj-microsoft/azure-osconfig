cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_FreeBSD_14_v1_0_0_2_1 STATIC FreeBSD_14_v1.0.0_2_1.c)

target_link_libraries(benchmarks_cis_FreeBSD_14_v1_0_0_2_1 PUBLIC
    logging
    benchmarks_cis_FreeBSD_14_v1_0_0_2_1_1
)
