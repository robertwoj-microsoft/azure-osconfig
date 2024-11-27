cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2 STATIC SUSE_15_v1.1.1_3_5_3_2.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2_1
    benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2_2
    benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2_3
    benchmarks_cis_SUSE_15_v1_1_1_3_5_3_2_4
)
