cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)

add_library(benchmarks_cis_Debian_12_v1_1_0_2_3_3 STATIC Debian_12_v1.1.0_2_3_3.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0_2_3_3 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_2_3_3_1
    benchmarks_cis_Debian_12_v1_1_0_2_3_3_2
    benchmarks_cis_Debian_12_v1_1_0_2_3_3_3
)
