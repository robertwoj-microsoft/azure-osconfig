cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Alma_9_v3_0_0_6_2 STATIC Alma_9_v3.0.0_6_2.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_6_2 PUBLIC
    logging
    benchmarks_cis_Alma_9_v3_0_0_6_2_1
    benchmarks_cis_Alma_9_v3_0_0_6_2_2
    benchmarks_cis_Alma_9_v3_0_0_6_2_3
    benchmarks_cis_Alma_9_v3_0_0_6_2_4
)
