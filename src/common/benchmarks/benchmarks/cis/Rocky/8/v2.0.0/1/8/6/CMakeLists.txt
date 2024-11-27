cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Rocky_8_v2_0_0_1_8_6 STATIC Rocky_8_v2.0.0_1_8_6.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_1_8_6 PUBLIC
    logging
    commonutils
)
