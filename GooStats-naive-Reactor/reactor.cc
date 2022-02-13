/*****************************************************************************/
// Author: Xuefeng Ding <xuefeng.ding.physics@gmail.com>
// Insitute: Gran Sasso Science Institute, L'Aquila, 67100, Italy
// Date: 2018 April 7th
// Version: v1.0
// Description: GooStats, a statistical analysis toolkit that runs on GPU.
//
// All rights reserved. 2018 copyrighted.
/*****************************************************************************/
#include "AnalysisManager.h"
#include "InputManager.h"
#include "ReactorInputBuilder.h"
#include "ReactorSpectrumBuilder.h"
#include "OutputManager.h"
#include "SimpleOutputBuilder.h"
#include "SimplePlotManager.h"
#include "GSFitManager.h"
#include "PrepareData.h"
#include "ContourManager.h"
#include "CorrelationManager.h"
#include "SimpleFit.h"
#include "ScanPar.h"
#include "NMOTest.h"

int main (int argc, const char* argv[]) {
  auto ana = new AnalysisManager();
  auto inputManager = new InputManager(argc,argv);
  InputBuilder *builder = new ReactorInputBuilder();
  builder->installSpectrumBuilder(new ReactorSpectrumBuilder());
  inputManager->setInputBuilder(builder);

  auto gsFitManager = new GSFitManager();

  auto outManager = new OutputManager();
  outManager->setOutputBuilder(new SimpleOutputBuilder());

  StatModule::setup(inputManager);
  StatModule::setup(gsFitManager);
  StatModule::setup(outManager);

  PlotManager *plotManager = new SimplePlotManager();
  outManager->setPlotManager(plotManager);

  auto data = new PrepareData();
  auto fit = new SimpleFit();
  auto nmo = new NMOTest();
  auto scan = new ScanPar();
  auto correlationManager = new CorrelationManager();
  auto contourManager = new ContourManager();

  ana->registerModule(inputManager);
  ana->registerModule(data);
  ana->registerModule(fit);
  ana->registerModule(nmo);
  ana->registerModule(scan);
  ana->registerModule(correlationManager);
  ana->registerModule(contourManager);
  ana->registerModule(outManager);

  ana->init();
  ana->run();
  ana->finish();

  return 0;
}
