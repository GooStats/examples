goofit_add_library(SinPdf STATIC SinPdf.cu)
target_link_libraries(SinPdf PUBLIC GooFit::goofit_lib)

goofit_add_library(fit STATIC fit.cc)
target_link_libraries(fit PUBLIC SinPdf)
