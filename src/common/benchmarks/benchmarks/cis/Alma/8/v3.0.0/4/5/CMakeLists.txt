cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Alma_8_v3_0_0_4_5 STATIC Alma_8_v3.0.0_4_5.c)

target_link_libraries(benchmarks_cis_Alma_8_v3_0_0_4_5 PUBLIC
    logging
    benchmarks_cis_Alma_8_v3_0_0_4_5_1
    benchmarks_cis_Alma_8_v3_0_0_4_5_2
    benchmarks_cis_Alma_8_v3_0_0_4_5_3
)
