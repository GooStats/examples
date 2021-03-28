#include "gtest/gtest.h"
#include "goofit/Variable.h"
#include "goofit/BinnedDataSet.h"
#include "TRandom.h"
#include "SinPdf.h"
#include "goofit/PDFs/SumPdf.h"
#include "goofit/FitManager.h"

TEST (GooFitTest, FirstTest) {
  Variable *energy = new Variable("energy",1,100); // nbins = 100
  BinnedDataSet *data = new BinnedDataSet(energy);
  gRandom->SetSeed(1);
  for(int i = 0;i<100;++i) {
    data->setBinContent(i,gRandom->Poisson(1000*(sin((i+0.5)/110*3.14+0.2)+1)));
  }
  Variable *alpha = new Variable("alpha",3.14/110,0.1/110,3.14/110*0.1,3.14/110*10);
  Variable *beta = new Variable("beta",0.2,0.002,-3.14,3.14);
  GooPdf *pdf = new SinPdf("sin",energy,alpha,beta);
  std::vector<Variable*> Ns;
  Ns.push_back(new Variable("N",1000,1,0,10000));
  std::vector<PdfBase*> pdfs;
  pdfs.push_back(pdf);
  SumPdf *likelihood = new SumPdf("likelihood",1,Ns,pdfs,energy);
  likelihood->setData(data);

  FitManager *fit = new FitManager(likelihood);
  fit->fit();
  fit->getMinuitValues();

  EXPECT_NEAR(Ns.front()->value,1000,10);
  EXPECT_NEAR(alpha->value,3.14/110,3.14/110*1e-2);
  EXPECT_NEAR(beta->value,0.2,0.2*5e-2);
}
