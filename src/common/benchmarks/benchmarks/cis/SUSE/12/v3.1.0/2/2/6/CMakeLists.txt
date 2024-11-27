cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_SUSE_12_v3_1_0_2_2_6 STATIC SUSE_12_v3.1.0_2_2_6.c)

target_link_libraries(benchmarks_cis_SUSE_12_v3_1_0_2_2_6 PUBLIC
    logging
    commonutils
)
