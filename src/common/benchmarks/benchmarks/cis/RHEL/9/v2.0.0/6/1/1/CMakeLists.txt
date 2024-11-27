cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_RHEL_9_v2_0_0_6_1_1 STATIC RHEL_9_v2.0.0_6_1_1.c)

target_link_libraries(benchmarks_cis_RHEL_9_v2_0_0_6_1_1 PUBLIC
    logging
    commonutils
)
