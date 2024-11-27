cmake_minimum_required(VERSION 3.2)

add_subdirectory(7)
add_subdirectory(8)
add_subdirectory(9)

add_library(benchmarks_cis_Oracle STATIC Oracle.c)

target_link_libraries(benchmarks_cis_Oracle PUBLIC
    logging
    benchmarks_cis_Oracle_7
    benchmarks_cis_Oracle_8
    benchmarks_cis_Oracle_9
)
