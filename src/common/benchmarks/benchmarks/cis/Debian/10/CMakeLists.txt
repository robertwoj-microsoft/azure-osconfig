cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Debian_10 STATIC Debian_10.c)

target_link_libraries(benchmarks_cis_Debian_10 PUBLIC
    logging
    benchmarks_cis_Debian_10_v2_0_0
)
