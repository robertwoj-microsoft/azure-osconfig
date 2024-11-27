cmake_minimum_required(VERSION 3.2)

add_subdirectory(7)
add_subdirectory(9)

add_library(benchmarks_cis_RHEL STATIC RHEL.c)

target_link_libraries(benchmarks_cis_RHEL PUBLIC
    logging
    benchmarks_cis_RHEL_7
    benchmarks_cis_RHEL_9
)
