cmake_minimum_required(VERSION 3.2)

add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Alma STATIC Alma.c)

target_link_libraries(benchmarks_cis_Alma PUBLIC
    logging
    benchmarks_cis_Alma_8
    benchmarks_cis_Alma_9
)
