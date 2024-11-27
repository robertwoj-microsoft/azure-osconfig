cmake_minimum_required(VERSION 3.2)

add_subdirectory(v3.0.0)

add_library(benchmarks_cis_Alma_8 STATIC Alma_8.c)

target_link_libraries(benchmarks_cis_Alma_8 PUBLIC
    logging
    benchmarks_cis_Alma_8_v3_0_0
)
