cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Azure_3_v1_0_0_5_2_6 STATIC Azure_3_v1.0.0_5_2_6.c)

target_link_libraries(benchmarks_cis_Azure_3_v1_0_0_5_2_6 PUBLIC
    logging
    commonutils
)
