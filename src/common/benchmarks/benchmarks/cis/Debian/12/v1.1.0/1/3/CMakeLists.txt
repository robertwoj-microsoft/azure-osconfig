cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)

add_library(benchmarks_cis_Debian_12_v1_1_0_1_3 STATIC Debian_12_v1.1.0_1_3.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_1_3 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_1_3_1
)
