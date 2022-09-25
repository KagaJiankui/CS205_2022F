#include "arbmul.h"

const double pi = acos(-1.0);
using namespace std;

/**
 * @brief Evaluate the bit-wise reversion of the input number in the region of
 * given length.
 *
 * @param x
 * @param len
 * @return int
 */
int rev(int x, int len)
{
  int ans = 0;
  while (len--) {
    ans <<= 1;
    ans |= x & 1;
    x >>= 1;
  }
  return ans;
}
/**
 * @brief Get the MSB digits of the input number using `BSR` instruction of the
 * x86 CPU.
 * @author https://www.zhihu.com/question/35361094/answer/1648676503
 *
 * @param x
 * @return int
 */
int getlog2(int x)
{
  return sizeof(int) * CHAR_BIT - 1 - __builtin_clz(x);
}

/**
 * @brief DIF-2 FFT function. Warning: The input of the FFT function must be inverted.
 * @author https://yexiaorain.github.io/Blog/2019-01-02-fftmul
 *
 * @param A complex vector operand
 * @param flag 1 for FFT, -1 for IFFT
 */
void FFT(vector<complex<double>>& A, int flag)
{
  int n = A.size();
  if (n == 1) return;
  assert((n & (n - 1)) == 0);
  int lgn = getlog2(n);
  for (int i = 0; i < n; i++) {
    int j = rev(i, lgn);
    if (j > i) swap(A[i], A[j]);
  }
  for (int pwr = 0; pwr < lgn; pwr++) {
    int             m = 1 << pwr;
    complex<double> Wm(cos(pi / m), -sin(pi / m) * flag);
    for (int k = 0; k < n; k += (m << 1)) {
      complex<double> W(1, 0);
      for (int j = 0; j < m; j++) {
        auto U       = A[k + j];
        auto T       = W * A[k + j + m];
        A[k + j]     = U + T;
        A[k + j + m] = U - T;
        W *= Wm;
      }
    }
  }
}