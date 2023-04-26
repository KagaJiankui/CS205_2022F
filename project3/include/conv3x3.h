#ifndef CONV3X3_H
#define CONV3X3_H

#define KSIZE3x3 3
#define KLEN3x3 9

void convolution3x3s1(const float *src, const int H, const int W, const float *kernel, float *dst, int H_out, int W_out);

#endif // CONV3X3_H