cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_RHEL_9_v2_0_0_5_1_12 STATIC RHEL_9_v2.0.0_5_1_12.c)

target_link_libraries(benchmarks_cis_RHEL_9_v2_0_0_5_1_12 PUBLIC
    logging
    commonutils
)
