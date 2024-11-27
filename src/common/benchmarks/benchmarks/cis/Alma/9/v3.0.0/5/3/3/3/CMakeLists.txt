cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Alma_9_v3_0_0_5_3_3_3 STATIC Alma_9_v3.0.0_5_3_3_3.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_5_3_3_3 PUBLIC
    logging
    benchmarks_cis_Alma_9_v3_0_0_5_3_3_3_1
    benchmarks_cis_Alma_9_v3_0_0_5_3_3_3_2
    benchmarks_cis_Alma_9_v3_0_0_5_3_3_3_3
)
