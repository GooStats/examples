add_library(solarB8_module
  solarB8DatasetController.cc
  solarB8InputBuilder.cc
  solarB8SpectrumBuilder.cc)
target_link_libraries(solarB8_module PUBLIC GooStatsLib)
goofit_add_library(solarB8_gpu_module
  SolarNuOscPdf.cu)
target_link_libraries(solarB8_gpu_module PUBLIC GooStatsPDFs)
