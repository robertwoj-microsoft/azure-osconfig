cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)

add_library(benchmarks_cis_Debian_10_v2_0_0 STATIC Debian_10_v2.0.0.c)

target_link_libraries(benchmarks_cis_Debian_10_v2_0_0 PUBLIC
    logging
    benchmarks_cis_Debian_10_v2_0_0_1
    benchmarks_cis_Debian_10_v2_0_0_2
    benchmarks_cis_Debian_10_v2_0_0_3
    benchmarks_cis_Debian_10_v2_0_0_4
    benchmarks_cis_Debian_10_v2_0_0_5
    benchmarks_cis_Debian_10_v2_0_0_6
)
