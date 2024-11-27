cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)

add_library(benchmarks_cis_SUSE_15_v1_1_1_4 STATIC SUSE_15_v1.1.1_4.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_4 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1_4_2
)
