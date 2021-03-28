#include "gtest/gtest.h"
#include "fit2.h"

TEST (GooFitTest, FirstTest) {
  EXPECT_NEAR(fit2(),357.95898,0.00001);
}
