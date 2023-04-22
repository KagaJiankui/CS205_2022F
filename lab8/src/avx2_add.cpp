#include "addvector.h"

void vectorAdd(const myVector &vecA, const myVector &vecB, myVector &vec_result) {
  if (vecA.length != vecB.length) {
    printf("Vector length mismatch");
  } else {
    __m256d mul_vec = _mm256_setzero_pd();
    // double* dataA_ptr=vecA.data;
    for (int i = 0; i < vecA.length; i += 4) {
      __m256d vec_1 = _mm256_loadu_pd(&vecA.data[i]);
      __m256d vec_2 = _mm256_loadu_pd(&vecB.data[i]);
      __m256d mask =
          _mm256_cmp_pd(_mm256_set_pd(i + 3 > vecA.length, i + 2 > vecA.length, i + 1 > vecA.length, i > vecA.length), _mm256_setzero_pd(), _CMP_EQ_OQ);
      vec_1   = _mm256_and_pd(vec_1, mask);
      vec_2   = _mm256_and_pd(vec_2, mask);
      mul_vec = _mm256_add_pd(vec_1, vec_2);
      double *mul_arr = (double *)&mul_vec;
      double *mask_arr = (double *)&mask;
      if (mask_arr[0]!=0)
      {
        vec_result.data[i]=mul_vec[i];
      }
      if (mask_arr[1] != 0) {
        vec_result.data[i+1] = mul_vec[i+1];
      }
      if (mask_arr[2] != 0) {
        vec_result.data[i+2] = mul_vec[i+2];
      }
      if (mask_arr[3] != 0) {
        vec_result.data[i+3] = mul_vec[i+3];
      }
    }
  }
}