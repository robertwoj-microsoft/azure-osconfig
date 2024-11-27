cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Oracle_7_v4_0_0_4_1_1_8 STATIC Oracle_7_v4.0.0_4_1_1_8.c)

target_link_libraries(benchmarks_cis_Oracle_7_v4_0_0_4_1_1_8 PUBLIC
    logging
    commonutils
)
