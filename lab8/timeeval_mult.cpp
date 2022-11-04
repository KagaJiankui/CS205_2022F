#include "matoperation.h"
#include "timeeval.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int EvalMatMultTime(int argc, char** argv)
{
  size_t nSize = 200000000;
  // float * p1 = new float[nSize](); //the memory is not aligned
  // float * p2 = new float[nSize](); //the memory is not aligned

  // 256bits aligned, C++17 standard
  float* p1     = static_cast<float*>(aligned_alloc(256, nSize * sizeof(float)));
  float* p2     = static_cast<float*>(aligned_alloc(256, nSize * sizeof(float)));
  float  result = 0.0f;

  p1[2]         = 2.3f;
  p2[2]         = 3.0f;
  p1[nSize - 1] = 2.0f;
  p2[nSize - 1] = 1.1f;

  auto start    = std::chrono::steady_clock::now();
  auto end      = std::chrono::steady_clock::now();
  auto duration = 0L;

  result = dotproduct(p1, p2, nSize);
  result = dotproduct(p1, p2, nSize);

  TIME_START
  result = dotproduct(p1, p2, nSize);
  TIME_END("normal")

  TIME_START
  result = dotproduct_unloop(p1, p2, nSize);
  TIME_END("unloop")

  TIME_START
  result = dotproduct_neon(p1, p2, nSize);
  TIME_END("SIMD")

  TIME_START
  result = dotproduct_neon_omp(p1, p2, nSize);
  TIME_END("SIMD+OpenMP")

  delete[] p1;
  delete[] p2;

  return 0;
}