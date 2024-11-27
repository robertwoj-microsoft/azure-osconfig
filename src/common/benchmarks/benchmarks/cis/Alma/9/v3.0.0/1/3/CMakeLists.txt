cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Alma_9_v3_0_0_1_3 STATIC Alma_9_v3.0.0_1_3.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_1_3 PUBLIC
    logging
    benchmarks_cis_Alma_9_v3_0_0_1_3_1
)
