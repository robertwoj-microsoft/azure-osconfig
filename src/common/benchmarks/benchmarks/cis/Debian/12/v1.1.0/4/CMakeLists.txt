cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)

add_library(benchmarks_cis_Debian_12_v1_1_0_4 STATIC Debian_12_v1.1.0_4.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_4 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_4_1
    benchmarks_cis_Debian_12_v1_1_0_4_2
    benchmarks_cis_Debian_12_v1_1_0_4_3
    benchmarks_cis_Debian_12_v1_1_0_4_4
)
