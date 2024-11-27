cmake_minimum_required(VERSION 3.2)

find_package(GTest REQUIRED)

add_executable(test_benchmarks_cis_SUSE_15_v1_1_1_5_6 SUSE_15_v1.1.1_5_6_test.cpp)
target_link_libraries(test_benchmarks_cis_SUSE_15_v1_1_1_5_6 PRIVATE GTest::GTest GTest::Main benchmarks_cis_SUSE_15_v1_1_1_5_6)

gtest_discover_tests(test_benchmarks_cis_SUSE_15_v1_1_1_5_6 XML_OUTPUT_DIR ${GTEST_OUTPUT_DIR})
