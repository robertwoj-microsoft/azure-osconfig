cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Debian_10_v2_0_0_1_1_5 STATIC Debian_10_v2.0.0_1_1_5.c)

target_link_libraries(benchmarks_cis_Debian_10_v2_0_0_1_1_5 PUBLIC
    logging
    benchmarks_cis_Debian_10_v2_0_0_1_1_5_2
    benchmarks_cis_Debian_10_v2_0_0_1_1_5_3
    benchmarks_cis_Debian_10_v2_0_0_1_1_5_4
)
