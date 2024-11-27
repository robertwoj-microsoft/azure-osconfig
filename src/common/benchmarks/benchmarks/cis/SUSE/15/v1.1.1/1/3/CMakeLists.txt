cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_SUSE_15_v1_1_1_1_3 STATIC SUSE_15_v1.1.1_1_3.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_1_3 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1_1_3_1
    benchmarks_cis_SUSE_15_v1_1_1_1_3_2
    benchmarks_cis_SUSE_15_v1_1_1_1_3_3
)
