cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Alma_8_v3_0_0_2_2_12 STATIC Alma_8_v3.0.0_2_2_12.c)

target_link_libraries(benchmarks_cis_Alma_8_v3_0_0_2_2_12 PUBLIC
    logging
    commonutils
)
