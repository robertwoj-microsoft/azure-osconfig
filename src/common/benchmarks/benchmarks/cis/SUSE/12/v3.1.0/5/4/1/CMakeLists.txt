cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_SUSE_12_v3_1_0_5_4_1 STATIC SUSE_12_v3.1.0_5_4_1.c)

target_link_libraries(benchmarks_cis_SUSE_12_v3_1_0_5_4_1 PUBLIC
    logging
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_1
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_2
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_3
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_4
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_5
    benchmarks_cis_SUSE_12_v3_1_0_5_4_1_6
)
