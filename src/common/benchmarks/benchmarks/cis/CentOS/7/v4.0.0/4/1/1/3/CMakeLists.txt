cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_CentOS_7_v4_0_0_4_1_1_3 STATIC CentOS_7_v4.0.0_4_1_1_3.c)

target_link_libraries(benchmarks_cis_CentOS_7_v4_0_0_4_1_1_3 PUBLIC
    logging
    commonutils
)
