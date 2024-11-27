cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Oracle_8_v3_0_0_6_1_9 STATIC Oracle_8_v3.0.0_6_1_9.c)

target_link_libraries(benchmarks_cis_Oracle_8_v3_0_0_6_1_9 PUBLIC
    logging
    commonutils
)
