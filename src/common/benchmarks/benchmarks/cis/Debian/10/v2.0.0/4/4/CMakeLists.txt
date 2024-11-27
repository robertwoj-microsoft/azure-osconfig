cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)

add_library(benchmarks_cis_Debian_10_v2_0_0_4_4 STATIC Debian_10_v2.0.0_4_4.c)

target_link_libraries(benchmarks_cis_Debian_10_v2_0_0_4_4 PUBLIC
    logging
    benchmarks_cis_Debian_10_v2_0_0_4_4_1
    benchmarks_cis_Debian_10_v2_0_0_4_4_2
    benchmarks_cis_Debian_10_v2_0_0_4_4_3
    benchmarks_cis_Debian_10_v2_0_0_4_4_4
    benchmarks_cis_Debian_10_v2_0_0_4_4_5
)
