cmake_minimum_required(VERSION 3.2)

add_subdirectory(v2.0.0)

add_library(benchmarks_cis_Debian_11 STATIC Debian_11.c)

target_link_libraries(benchmarks_cis_Debian_11 PUBLIC
    logging
    benchmarks_cis_Debian_11_v2_0_0
)
