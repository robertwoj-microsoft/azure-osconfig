cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Debian_11_v2_0_0_6_2_1_2 STATIC Debian_11_v2.0.0_6_2_1_2.c)

target_link_libraries(benchmarks_cis_Debian_11_v2_0_0_6_2_1_2 PUBLIC
    logging
    benchmarks_cis_Debian_11_v2_0_0_6_2_1_2_1
    benchmarks_cis_Debian_11_v2_0_0_6_2_1_2_2
    benchmarks_cis_Debian_11_v2_0_0_6_2_1_2_3
    benchmarks_cis_Debian_11_v2_0_0_6_2_1_2_4
)
