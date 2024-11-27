cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Alma_8_v3_0_0_1_1 STATIC Alma_8_v3.0.0_1_1.c)

target_link_libraries(benchmarks_cis_Alma_8_v3_0_0_1_1 PUBLIC
    logging
    benchmarks_cis_Alma_8_v3_0_0_1_1_1
    benchmarks_cis_Alma_8_v3_0_0_1_1_2
)
