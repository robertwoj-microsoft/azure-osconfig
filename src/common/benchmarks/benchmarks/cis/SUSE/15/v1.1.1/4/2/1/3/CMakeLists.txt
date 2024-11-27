cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_SUSE_15_v1_1_1_4_2_1_3 STATIC SUSE_15_v1.1.1_4_2_1_3.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_4_2_1_3 PUBLIC
    logging
    commonutils
)
