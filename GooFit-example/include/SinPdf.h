#ifndef Sin_PDF_HH
#define Sin_PDF_HH

#include "goofit/PDFs/GooPdf.h" 

class SinPdf : public GooPdf {
public:
  SinPdf (std::string n, Variable* _x, Variable* alpha, Variable* beta); 
  __host__ fptype integrate (fptype lo, fptype hi) const; 
  __host__ virtual bool hasAnalyticIntegral () const {return (1 == host_indices[parameters]);} 



private:

};

#endif
