cmake_minimum_required(VERSION 3.2)

add_subdirectory(v4.0.0)

add_library(benchmarks_cis_RHEL_7 STATIC RHEL_7.c)

target_link_libraries(benchmarks_cis_RHEL_7 PUBLIC
    logging
    benchmarks_cis_RHEL_7_v4_0_0
)
