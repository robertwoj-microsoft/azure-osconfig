cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(5)

add_library(benchmarks_cis_SUSE_12_v3_1_0_3 STATIC SUSE_12_v3.1.0_3.c)

target_link_libraries(benchmarks_cis_SUSE_12_v3_1_0_3 PUBLIC
    logging
    benchmarks_cis_SUSE_12_v3_1_0_3_1
    benchmarks_cis_SUSE_12_v3_1_0_3_2
    benchmarks_cis_SUSE_12_v3_1_0_3_3
    benchmarks_cis_SUSE_12_v3_1_0_3_5
)
