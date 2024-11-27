cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(15)
add_subdirectory(16)
add_subdirectory(17)
add_subdirectory(18)
add_subdirectory(19)
add_subdirectory(2)
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_SUSE_15_v1_1_1_5_2 STATIC SUSE_15_v1.1.1_5_2.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_5_2 PUBLIC
    logging
    benchmarks_cis_SUSE_15_v1_1_1_5_2_1
    benchmarks_cis_SUSE_15_v1_1_1_5_2_10
    benchmarks_cis_SUSE_15_v1_1_1_5_2_11
    benchmarks_cis_SUSE_15_v1_1_1_5_2_12
    benchmarks_cis_SUSE_15_v1_1_1_5_2_13
    benchmarks_cis_SUSE_15_v1_1_1_5_2_14
    benchmarks_cis_SUSE_15_v1_1_1_5_2_15
    benchmarks_cis_SUSE_15_v1_1_1_5_2_16
    benchmarks_cis_SUSE_15_v1_1_1_5_2_17
    benchmarks_cis_SUSE_15_v1_1_1_5_2_18
    benchmarks_cis_SUSE_15_v1_1_1_5_2_19
    benchmarks_cis_SUSE_15_v1_1_1_5_2_2
    benchmarks_cis_SUSE_15_v1_1_1_5_2_21
    benchmarks_cis_SUSE_15_v1_1_1_5_2_22
    benchmarks_cis_SUSE_15_v1_1_1_5_2_3
    benchmarks_cis_SUSE_15_v1_1_1_5_2_4
    benchmarks_cis_SUSE_15_v1_1_1_5_2_5
    benchmarks_cis_SUSE_15_v1_1_1_5_2_7
    benchmarks_cis_SUSE_15_v1_1_1_5_2_8
    benchmarks_cis_SUSE_15_v1_1_1_5_2_9
)
