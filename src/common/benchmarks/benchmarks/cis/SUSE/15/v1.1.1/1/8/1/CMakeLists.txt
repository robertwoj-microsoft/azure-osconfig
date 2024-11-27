cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_SUSE_15_v1_1_1_1_8_1 STATIC SUSE_15_v1.1.1_1_8_1.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_1_8_1 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_1
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_2
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_3
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_4
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_5
    benchmarks_cis_SUSE_15_v1_1_1_1_8_1_6
)
