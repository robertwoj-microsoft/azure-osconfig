cmake_minimum_required(VERSION 3.2)

add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)

add_library(benchmarks_cis_Debian STATIC Debian.c)

target_link_libraries(benchmarks_cis_Debian PUBLIC
    logging
    benchmarks_cis_Debian_10
    benchmarks_cis_Debian_11
    benchmarks_cis_Debian_12
)
