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
#include "SimpleInputBuilder.h"
#include "OutputManager.h"
#include "SimpleOutputBuilder.h"
#include "SimplePlotManager.h"
#include "GSFitManager.h"
#include "PrepareData.h"
#include "SimpleFit.h"
#include "OutputHelper.h"

double fit2() {
  AnalysisManager *ana = new AnalysisManager();

  const char *argv[2] = {"exe","toyMC.cfg"};
  InputManager *inputManager = new InputManager(2,argv);
  inputManager->setInputBuilder(new SimpleInputBuilder());
  GSFitManager *gsFitManager = new GSFitManager();
  OutputManager *outManager = new OutputManager();
  outManager->setOutputBuilder(new SimpleOutputBuilder());
  outManager->setPlotManager(new SimplePlotManager());

  StatModule::setup(inputManager);
  StatModule::setup(gsFitManager);
  StatModule::setup(outManager);

  PrepareData *data = new PrepareData();
  SimpleFit *fit = new SimpleFit();

  ana->registerModule(inputManager);
  ana->registerModule(data);
  ana->registerModule(fit);
  ana->registerModule(outManager);

  ana->init();
  ana->run();
  ana->finish();
  auto outputHelper = outManager->getOutputHelper();

  return outputHelper->value("likelihood");
}
