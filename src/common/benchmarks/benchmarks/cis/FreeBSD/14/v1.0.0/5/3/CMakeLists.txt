cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_FreeBSD_14_v1_0_0_5_3 STATIC FreeBSD_14_v1.0.0_5_3.c)

target_link_libraries(benchmarks_cis_FreeBSD_14_v1_0_0_5_3 PUBLIC
    logging
    benchmarks_cis_FreeBSD_14_v1_0_0_5_3_1
    benchmarks_cis_FreeBSD_14_v1_0_0_5_3_2
    benchmarks_cis_FreeBSD_14_v1_0_0_5_3_3
)
