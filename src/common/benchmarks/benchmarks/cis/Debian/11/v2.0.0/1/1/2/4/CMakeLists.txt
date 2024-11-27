cmake_minimum_required(VERSION 3.2)

add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Debian_11_v2_0_0_1_1_2_4 STATIC Debian_11_v2.0.0_1_1_2_4.c)

target_link_libraries(benchmarks_cis_Debian_11_v2_0_0_1_1_2_4 PUBLIC
    logging
    benchmarks_cis_Debian_11_v2_0_0_1_1_2_4_2
    benchmarks_cis_Debian_11_v2_0_0_1_1_2_4_3
)
