cmake_minimum_required(VERSION 3.15)

project(testFit)

### include utilities
include(FetchContent)

FetchContent_Declare(
  GooFit
  GIT_REPOSITORY https://github.com/GooStats/GooFit
  GIT_TAG        v2.1.1
  )
FetchContent_MakeAvailable(GooFit)
add_library(GooFit::goofit_lib ALIAS goofit_lib)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(src)

add_executable(testFit main.cc)
target_link_libraries(testFit PRIVATE SinPdf)

# test
enable_testing()
set (case_name test_${case_name})
add_executable(testGooFit test.cc)
target_link_libraries(testGooFit GooFit::goofit_lib SinPdf gtest_main)
add_test(NAME testGooFit
  COMMAND $<TARGET_FILE:testGooFit>
  WORKING_DIRECTORY
  ${PROJECT_BINARY_DIR})
