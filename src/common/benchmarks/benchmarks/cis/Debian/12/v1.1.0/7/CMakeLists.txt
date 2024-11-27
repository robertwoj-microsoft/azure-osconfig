cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)

add_library(benchmarks_cis_Debian_12_v1_1_0_7 STATIC Debian_12_v1.1.0_7.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_7 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_7_1
    benchmarks_cis_Debian_12_v1_1_0_7_2
)
