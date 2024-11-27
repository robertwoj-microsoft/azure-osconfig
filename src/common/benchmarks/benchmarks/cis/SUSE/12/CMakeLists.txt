cmake_minimum_required(VERSION 3.2)

add_subdirectory(v3.1.0)

add_library(benchmarks_cis_SUSE_12 STATIC SUSE_12.c)

target_link_libraries(benchmarks_cis_SUSE_12 PUBLIC
    logging
    benchmarks_cis_SUSE_12_v3_1_0
)
