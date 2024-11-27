cmake_minimum_required(VERSION 3.2)

add_subdirectory(12)
add_subdirectory(15)

add_library(benchmarks_cis_SUSE STATIC SUSE.c)

target_link_libraries(benchmarks_cis_SUSE PUBLIC
    logging
    benchmarks_cis_SUSE_12
    benchmarks_cis_SUSE_15
)
