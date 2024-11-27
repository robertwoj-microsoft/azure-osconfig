cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(8)

add_library(benchmarks_cis_Debian_11_v2_0_0_1_1_1 STATIC Debian_11_v2.0.0_1_1_1.c)

target_link_libraries(benchmarks_cis_Debian_11_v2_0_0_1_1_1 PUBLIC
    logging
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_1
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_2
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_3
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_4
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_5
    benchmarks_cis_Debian_11_v2_0_0_1_1_1_8
)
