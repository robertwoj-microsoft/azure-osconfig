cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Rocky_8_v2_0_0_3_4_2_1 STATIC Rocky_8_v2.0.0_3_4_2_1.c)

target_link_libraries(benchmarks_cis_Rocky_8_v2_0_0_3_4_2_1 PUBLIC
    logging
    commonutils
)
