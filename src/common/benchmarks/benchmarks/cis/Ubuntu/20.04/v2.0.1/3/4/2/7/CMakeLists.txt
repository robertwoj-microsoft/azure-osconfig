cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_7 STATIC Ubuntu_20.04_v2.0.1_3_4_2_7.c)

target_link_libraries(benchmarks_cis_Ubuntu_20_04_v2_0_1_3_4_2_7 PUBLIC
    logging
    commonutils
)
