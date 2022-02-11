cmake_minimum_required(VERSION 3.15)
project(GooStats-fit)

### include utilities
include(GNUInstallDirs)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
add_library(GooStats-simpleFit-lib fit2.cc)
target_link_libraries(GooStats-simpleFit-lib GooStatsLib)

add_executable(GooStats-simpleFit main.cc)
target_link_libraries(GooStats-simpleFit GooStats-simpleFit-lib)

file(COPY toyMC.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(testGooStatstest test.cc)
target_link_libraries(testGooStatstest GooStats-simpleFit-lib gtest_main)
add_test(NAME testGooStatstest
        COMMAND $<TARGET_FILE:testGooStatstest>)
