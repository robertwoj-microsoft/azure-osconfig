cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_5_5 STATIC Ubuntu_18.04_v2.2.0_1_5_5.c)

target_link_libraries(benchmarks_cis_Ubuntu_18_04_v2_2_0_1_5_5 PUBLIC
    logging
    commonutils
)
