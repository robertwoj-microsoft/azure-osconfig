cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Alma_8_v3_0_0_4_2_10 STATIC Alma_8_v3.0.0_4_2_10.c)

target_link_libraries(benchmarks_cis_Alma_8_v3_0_0_4_2_10 PUBLIC
    logging
    commonutils
)
