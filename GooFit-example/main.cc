#include "fit.h"
#include <iostream>

int main() {
  double a,b,c;

  run(a,b,c);

  std::cout<<"N: "<<a<<" (expect "<<1000<<")"<<std::endl;
  std::cout<<"alpha: "<<b<<" (expect "<<3.14/110<<")"<<std::endl;
  std::cout<<"beta: "<<c<<" (expect "<<0.2<<")"<<std::endl;

  return 0;
}
