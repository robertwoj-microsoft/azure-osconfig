cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_RHEL_7_v4_0_0_1_2_4 STATIC RHEL_7_v4.0.0_1_2_4.c)

target_link_libraries(benchmarks_cis_RHEL_7_v4_0_0_1_2_4 PUBLIC
    logging
    commonutils
)
