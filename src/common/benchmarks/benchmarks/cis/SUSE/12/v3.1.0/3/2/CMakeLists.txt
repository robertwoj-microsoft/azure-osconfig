cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_SUSE_12_v3_1_0_3_2 STATIC SUSE_12_v3.1.0_3_2.c)

target_link_libraries(benchmarks_cis_SUSE_12_v3_1_0_3_2 PUBLIC
    logging
    benchmarks_cis_SUSE_12_v3_1_0_3_2_1
    benchmarks_cis_SUSE_12_v3_1_0_3_2_2
)
