cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Alma_9_v3_0_0_5_4_2_2 STATIC Alma_9_v3.0.0_5_4_2_2.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_5_4_2_2 PUBLIC
    logging
    commonutils
)
