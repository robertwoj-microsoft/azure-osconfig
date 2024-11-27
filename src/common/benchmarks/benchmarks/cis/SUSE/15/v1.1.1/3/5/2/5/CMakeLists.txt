cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_SUSE_15_v1_1_1_3_5_2_5 STATIC SUSE_15_v1.1.1_3_5_2_5.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_3_5_2_5 PUBLIC
    logging
    commonutils
)
