cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_RHEL_7_v4_0_0_3_4 STATIC RHEL_7_v4.0.0_3_4.c)

target_link_libraries(benchmarks_cis_RHEL_7_v4_0_0_3_4 PUBLIC
    logging
    benchmarks_cis_RHEL_7_v4_0_0_3_4_1
    benchmarks_cis_RHEL_7_v4_0_0_3_4_2
    benchmarks_cis_RHEL_7_v4_0_0_3_4_3
    benchmarks_cis_RHEL_7_v4_0_0_3_4_4
)
