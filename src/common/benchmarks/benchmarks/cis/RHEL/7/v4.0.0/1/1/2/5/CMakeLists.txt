cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_RHEL_7_v4_0_0_1_1_2_5 STATIC RHEL_7_v4.0.0_1_1_2_5.c)

target_link_libraries(benchmarks_cis_RHEL_7_v4_0_0_1_1_2_5 PUBLIC
    logging
    benchmarks_cis_RHEL_7_v4_0_0_1_1_2_5_2
    benchmarks_cis_RHEL_7_v4_0_0_1_1_2_5_3
    benchmarks_cis_RHEL_7_v4_0_0_1_1_2_5_4
)
