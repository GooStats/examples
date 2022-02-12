################
# Define a test

add_executable(autoTest autoTest.cc)
target_link_libraries(autoTest PRIVATE BestFitFixture NLLFixture gtest_main)
target_link_libraries(autoTest PRIVATE reactor_module)
target_link_libraries(autoTest PRIVATE GooStatsLib)
if(COVERAGE OR DEFINED ENV{COVERAGE})
  message(STATUS "Enabling COVERAGE TEST")
  target_compile_options(autoTest PRIVATE --coverage)
  target_link_libraries(autoTest PRIVATE --coverage)
endif()
file(COPY ../data_recE.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ../data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME    autoTest
  COMMAND autoTest)