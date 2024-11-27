cmake_minimum_required(VERSION 3.2)

add_subdirectory(14)

add_library(benchmarks_cis_FreeBSD STATIC FreeBSD.c)

target_link_libraries(benchmarks_cis_FreeBSD PUBLIC
    logging
    benchmarks_cis_FreeBSD_14
)
