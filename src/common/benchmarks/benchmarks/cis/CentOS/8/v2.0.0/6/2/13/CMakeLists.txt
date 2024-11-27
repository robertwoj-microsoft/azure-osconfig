cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_CentOS_8_v2_0_0_6_2_13 STATIC CentOS_8_v2.0.0_6_2_13.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_6_2_13 PUBLIC
    logging
    commonutils
)
