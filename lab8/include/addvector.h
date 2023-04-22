#ifndef ADDVECTOR_H
#define ADDVECTOR_H

#include "myvector.h"

#ifdef __AVX2
  #include "immintrin.h"
  #ifdef _OMP_AND_AVX2
    #include <omp.h>
  #endif //_OMP_AND_AVX2
#endif   //__AVX2

void vectorAdd(const myVector &vecA, const myVector &vecB, myVector &vec_result);

#endif // ADDVECTOR_H