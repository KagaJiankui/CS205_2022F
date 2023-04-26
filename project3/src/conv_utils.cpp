#include "conv_utils.h"

void loadKernel(float *kernel, int len) {
  float temp = 0.0;
  for (int i = 0; i < len / 2; i++) {
    temp                = kernel[i];
    kernel[i]           = kernel[len - 1 - i];
    kernel[len - 1 - i] = temp;
  }
}