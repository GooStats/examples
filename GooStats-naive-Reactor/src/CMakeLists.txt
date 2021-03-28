add_library(reactor_module
  NMOTest.cc
  ReactorDatasetController.cc
  ReactorInputBuilder.cc
  ReactorSpectrumBuilder.cc)
target_link_libraries(reactor_module PUBLIC GooStatsLib)
