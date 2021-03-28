cmake_minimum_required(VERSION 3.15)

project(example)

add_subdirectory(extern/GooStats/GooStats)

include(extern/GooStats/GooStats/extern/GooStats/GooFit/extern/GooStats/cmake-utilities/INITIALIZE_CUDA.cmake)
INITIALIZE_CUDA()

enable_testing()
add_subdirectory(GooFit-example)
add_subdirectory(GooStats-simpleFit)
add_subdirectory(GooStats-statAnalysis)
add_subdirectory(GooStats-naive-Reactor)
#add_subdirectory(GooStats-solarB8Fit) # TODO
