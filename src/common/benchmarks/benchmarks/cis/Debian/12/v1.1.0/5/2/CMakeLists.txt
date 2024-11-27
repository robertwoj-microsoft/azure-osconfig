cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_Debian_12_v1_1_0_5_2 STATIC Debian_12_v1.1.0_5_2.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_5_2 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_5_2_1
    benchmarks_cis_Debian_12_v1_1_0_5_2_2
    benchmarks_cis_Debian_12_v1_1_0_5_2_3
    benchmarks_cis_Debian_12_v1_1_0_5_2_5
    benchmarks_cis_Debian_12_v1_1_0_5_2_6
    benchmarks_cis_Debian_12_v1_1_0_5_2_7
)
