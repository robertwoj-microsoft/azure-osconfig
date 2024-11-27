cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Debian_12_v1_1_0_6_1_2 STATIC Debian_12_v1.1.0_6_1_2.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_6_1_2 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_6_1_2_1
    benchmarks_cis_Debian_12_v1_1_0_6_1_2_2
    benchmarks_cis_Debian_12_v1_1_0_6_1_2_3
    benchmarks_cis_Debian_12_v1_1_0_6_1_2_4
)
