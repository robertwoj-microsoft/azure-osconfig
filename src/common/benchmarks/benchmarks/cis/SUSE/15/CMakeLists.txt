cmake_minimum_required(VERSION 3.2)

add_subdirectory(v1.1.1)

add_library(benchmarks_cis_SUSE_15 STATIC SUSE_15.c)

target_link_libraries(benchmarks_cis_SUSE_15 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1
)
