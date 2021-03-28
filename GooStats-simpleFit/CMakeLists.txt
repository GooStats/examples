cmake_minimum_required(VERSION 3.15)
project(GooStats-fit)

### include utilities
include(GNUInstallDirs)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
add_library(GooStats-simpleFit-lib fit2.cc)
target_link_libraries(GooStats-simpleFit-lib GooStatsLib)

add_executable(GooStats-simpleFit main.cc)
target_link_libraries(GooStats-simpleFit GooStats-simpleFit-lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/toyMC.cfg DESTINATION ${CMAKE_INSTALL_SYSCONFDIR})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_INSTALL_DATADIR})

add_executable(testGooStatstest test.cc)
target_link_libraries(testGooStatstest GooStats-simpleFit-lib gtest_main)
add_test(NAME testGooStatstest
  COMMAND $<TARGET_FILE:testGooFittest>
  WORKING_DIRECTORY
  ${CMAKE_CURRENT_LIST_DIR})
