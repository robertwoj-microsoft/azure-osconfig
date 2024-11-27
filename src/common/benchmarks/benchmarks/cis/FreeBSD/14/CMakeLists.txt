cmake_minimum_required(VERSION 3.2)

add_subdirectory(v1.0.0)

add_library(benchmarks_cis_FreeBSD_14 STATIC FreeBSD_14.c)

target_link_libraries(benchmarks_cis_FreeBSD_14 PUBLIC
    logging
    benchmarks_cis_FreeBSD_14_v1_0_0
)
