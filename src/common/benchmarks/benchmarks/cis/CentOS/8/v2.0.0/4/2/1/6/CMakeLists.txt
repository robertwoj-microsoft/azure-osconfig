cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_CentOS_8_v2_0_0_4_2_1_6 STATIC CentOS_8_v2.0.0_4_2_1_6.c)

target_link_libraries(benchmarks_cis_CentOS_8_v2_0_0_4_2_1_6 PUBLIC
    logging
    commonutils
)
