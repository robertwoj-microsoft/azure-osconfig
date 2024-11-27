cmake_minimum_required(VERSION 3.2)

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
add_subdirectory(5)
add_subdirectory(6)
add_subdirectory(7)

add_library(benchmarks_cis_Debian_12_v1_1_0 STATIC Debian_12_v1.1.0.c)

target_link_libraries(benchmarks_cis_Debian_12_v1_1_0 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0_1
    benchmarks_cis_Debian_12_v1_1_0_2
    benchmarks_cis_Debian_12_v1_1_0_3
    benchmarks_cis_Debian_12_v1_1_0_4
    benchmarks_cis_Debian_12_v1_1_0_5
    benchmarks_cis_Debian_12_v1_1_0_6
    benchmarks_cis_Debian_12_v1_1_0_7
)
