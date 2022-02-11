cmake_minimum_required(VERSION 3.15)
project(GooStats-naive-Reactor)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory(src)
add_subdirectory(tests)
add_executable(reactor reactor.cc)
target_link_libraries(reactor reactor_module)
target_link_libraries(reactor GooStatsLib)
