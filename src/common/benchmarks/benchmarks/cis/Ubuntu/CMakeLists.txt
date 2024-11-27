cmake_minimum_required(VERSION 3.2)

add_subdirectory(16.04)
add_subdirectory(18.04)
add_subdirectory(20.04)
add_subdirectory(22.04)
add_subdirectory(24.04)

add_library(benchmarks_cis_Ubuntu STATIC Ubuntu.c)

target_link_libraries(benchmarks_cis_Ubuntu PUBLIC
    logging
    benchmarks_cis_Ubuntu_16_04
    benchmarks_cis_Ubuntu_18_04
    benchmarks_cis_Ubuntu_20_04
    benchmarks_cis_Ubuntu_22_04
    benchmarks_cis_Ubuntu_24_04
)
