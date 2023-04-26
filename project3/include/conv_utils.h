#ifndef CONV_UTILS_H
#define CONV_UTILS_H

#include <cstdlib>
#include <cstring>
#include <immintrin.h>
#include <omp.h>

union M128 {
  __m128 m128;
  float  f32[4];
};
union M256 {
  __m256 m256;
  float  f32[8];
};

void loadKernel(float *kernel, int len);

#endif // CONV_COMMON_H