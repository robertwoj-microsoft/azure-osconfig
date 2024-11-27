cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Rocky_9_v2_0_0_4_3_2 STATIC Rocky_9_v2.0.0_4_3_2.c)

target_link_libraries(benchmarks_cis_Rocky_9_v2_0_0_4_3_2 PUBLIC
    logging
    commonutils
)
