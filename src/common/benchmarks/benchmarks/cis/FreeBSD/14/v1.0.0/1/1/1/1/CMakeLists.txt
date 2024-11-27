cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_FreeBSD_14_v1_0_0_1_1_1_1 STATIC FreeBSD_14_v1.0.0_1_1_1_1.c)

target_link_libraries(benchmarks_cis_FreeBSD_14_v1_0_0_1_1_1_1 PUBLIC
    logging
    commonutils
)
