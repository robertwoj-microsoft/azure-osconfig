cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Azure_3_v1_0_0_1_4_2 STATIC Azure_3_v1.0.0_1_4_2.c)

target_link_libraries(benchmarks_cis_Azure_3_v1_0_0_1_4_2 PUBLIC
    logging
    commonutils
)
