#include "conv3x3.h"

#include "conv_utils.h"

void convolution3x3s1(const float *src, const int H, const int W, const float *kernel, float *dst, int H_out, int W_out) {
  const int data_size = H * W;
  H_out               = H + 1 - KSIZE3x3;
  W_out               = W + 1 - KSIZE3x3;

  float *kernel_loaded = (float *)malloc(sizeof(float) * KLEN3x3);
  float *src_loaded    = (float *)malloc(sizeof(float) * KLEN3x3);
  memcpy(kernel_loaded, kernel, sizeof(double) * KLEN3x3);
  memset(src_loaded, 0, sizeof(double) * KLEN3x3);
  loadKernel(kernel_loaded, KLEN3x3);

  M256 k0_7;
  M256 k8;
  k0_7.m256 = _mm256_loadu_ps(kernel_loaded);
  k8.m256   = _mm256_setzero_ps();
  k8.f32[0] = kernel_loaded[8];

#if USE_OMP
  #pragma omp parallel for num_threads(OMP_THREAD)
#endif
  for (int i = 0; i < (H_out) * (W_out); i++) {
    M256 d0_7;
    M256 d8;
    M256 res0_7;
    M256 res8;
    src_loaded[0] = src[i];
    src_loaded[1] = src[i + 1];
    src_loaded[2] = src[i + 2];
    src_loaded[3] = src[i + W];
    src_loaded[4] = src[i + W + 1];
    src_loaded[5] = src[i + W + 2];
    src_loaded[6] = src[i + 2 * W];
    src_loaded[7] = src[i + 2 * W + 1];
    src_loaded[8] = src[i + 2 * W + 2];
    d0_7.m256     = _mm256_loadu_ps(src_loaded);
    d8.m256       = _mm256_setzero_ps();
    d8.f32[0]     = src_loaded[8];
    res0_7.m256   = _mm256_mul_ps(k0_7.m256, d0_7.m256);
    dst[i]        = res0_7.f32[0] + res0_7.f32[1] + res0_7.f32[2] + res0_7.f32[3] + res0_7.f32[4] + res0_7.f32[5] + res0_7.f32[6] + res0_7.f32[7] + k8.f32[0] * d8.f32[0];
  }
}