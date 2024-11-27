cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_SUSE_15_v1_1_1_1_1_18 STATIC SUSE_15_v1.1.1_1_1_18.c)

target_link_libraries(benchmarks_cis_SUSE_15_v1_1_1_1_1_18 PUBLIC
    logging
    commonutils
)
