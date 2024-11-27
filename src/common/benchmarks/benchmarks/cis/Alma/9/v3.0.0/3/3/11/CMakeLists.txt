cmake_minimum_required(VERSION 3.2)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()

add_library(benchmarks_cis_Alma_9_v3_0_0_3_3_11 STATIC Alma_9_v3.0.0_3_3_11.c)

target_link_libraries(benchmarks_cis_Alma_9_v3_0_0_3_3_11 PUBLIC
    logging
    commonutils
)
