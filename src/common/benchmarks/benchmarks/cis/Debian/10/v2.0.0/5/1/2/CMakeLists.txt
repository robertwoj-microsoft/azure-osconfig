cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_Debian_10_v2_0_0_5_1_2 STATIC Debian_10_v2.0.0_5_1_2.c)

target_link_libraries(benchmarks_cis_Debian_10_v2_0_0_5_1_2 PUBLIC
    logging
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_1
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_2
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_3
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_4
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_5
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_6
    benchmarks_cis_Debian_10_v2_0_0_5_1_2_7
)
