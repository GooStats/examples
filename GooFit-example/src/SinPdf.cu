#include "SinPdf.h"

EXEC_TARGET fptype device_Sin (fptype* evt, fptype* p, unsigned int* indices) {
  fptype x = evt[indices[2 + indices[0]]]; 
  fptype alpha = p[indices[1]];
  fptype beta = p[indices[2]];
  const int cIndex = RO_CACHE(indices[3]);
  const fptype drift = RO_CACHE(functorConstants[cIndex]); // ok

  fptype ret = SIN(alpha*x+beta)+1+drift; 
  return ret; 
}

MEM_DEVICE device_function_ptr ptr_to_Sin = device_Sin; 

__host__ SinPdf::SinPdf (std::string n, Variable* _x, Variable* alpha, Variable* beta,fptype drift) 
  : GooPdf(_x, n) 
{
  std::vector<unsigned int> pindices;
  pindices.push_back(registerParameter(alpha));
  pindices.push_back(registerParameter(beta));
  pindices.push_back(registerConstants(1)); // 5
  fptype hostConstants[1] = { drift };
  MEMCPY_TO_SYMBOL(functorConstants, hostConstants, sizeof(fptype), cIndex*sizeof(fptype), cudaMemcpyHostToDevice); 
  GET_FUNCTION_ADDR(ptr_to_Sin);
  initialise(pindices); 
}


__host__ fptype SinPdf::integrate (fptype lo, fptype hi) const {
  fptype alpha = host_params[host_indices[parameters + 1]]; 
  fptype beta = host_params[host_indices[parameters + 2]]; 
  if(alpha==0) return (SIN(beta)+1)*(hi-lo);

  fptype ret = (COS(alpha*lo+beta) - COS(alpha*hi+beta))/alpha+hi-lo;
  return ret; 
}

