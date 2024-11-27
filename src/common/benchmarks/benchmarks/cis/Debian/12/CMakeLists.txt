cmake_minimum_required(VERSION 3.2)

add_subdirectory(v1.1.0)

add_library(benchmarks_cis_Debian_12 STATIC Debian_12.c)

target_link_libraries(benchmarks_cis_Debian_12 PUBLIC
    logging
    benchmarks_cis_Debian_12_v1_1_0
)
