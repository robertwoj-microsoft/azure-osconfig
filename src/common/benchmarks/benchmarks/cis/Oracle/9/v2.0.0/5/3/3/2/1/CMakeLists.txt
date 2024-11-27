cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Oracle_9_v2_0_0_5_3_3_2_1 STATIC Oracle_9_v2.0.0_5_3_3_2_1.c)

target_link_libraries(benchmarks_cis_Oracle_9_v2_0_0_5_3_3_2_1 PUBLIC
    logging
    commonutils
)
