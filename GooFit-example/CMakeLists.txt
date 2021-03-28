cmake_minimum_required(VERSION 3.15)

project(testGooFit)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(src)

add_executable(testGooFit main.cc)
target_link_libraries(testGooFit PRIVATE SinPdf fit)

# test
add_executable(testGooFittest test.cc)
target_link_libraries(testGooFittest SinPdf fit gtest_main)
add_test(NAME testGooFittest
  COMMAND $<TARGET_FILE:testGooFittest>
  WORKING_DIRECTORY
  ${PROJECT_BINARY_DIR})
