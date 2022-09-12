#pragma once
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <vector>

int rev(int x, int len);
int getlog2(int x);
void FFT(std::vector<std::complex<double>> &A, int flag);