cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)

add_library(benchmarks_cis_SUSE_12_v3_1_0_5_4 STATIC SUSE_12_v3.1.0_5_4.c)

target_link_libraries(benchmarks_cis_SUSE_12_v3_1_0_5_4 PUBLIC
    logging
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1
    benchmarks_cis_SUSE_12_v3_1_0_5_4_2
    benchmarks_cis_SUSE_12_v3_1_0_5_4_3
    benchmarks_cis_SUSE_12_v3_1_0_5_4_4
    benchmarks_cis_SUSE_12_v3_1_0_5_4_5
)
