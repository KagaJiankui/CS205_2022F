#include "conv_utils.h"

#include "conv3x3.h"

int main(int argc, char const *argv[])
{
  float kernel1[9] = {0, 0, 1, 1, 2, 2, 3, 3, 4};
  float kernel2[9] = {0};
  convolution3x3s1(kernel1, 3, 3, kernel1, kernel2, 1, 1);
  return 0;
}
