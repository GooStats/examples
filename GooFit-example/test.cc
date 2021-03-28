#include "gtest/gtest.h"
#include "fit.h"

TEST (GooFitTest, FirstTest) {
  double a,b,c;
  run(a,b,c);
  EXPECT_NEAR(a,1000,10);
  EXPECT_NEAR(b,3.14/110,3.14/110*1e-2);
  EXPECT_NEAR(c,0.2,0.2*5e-2);
}
