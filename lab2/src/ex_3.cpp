#include <iostream>

int main(int argc, const char** argv) {
  /**
   * @brief 56789*23456789=1,332,087,590,521 exceeds 32 bit but is still within
   64 bit. In the ILP64 data length model of the Linux system, use `long` data
   type to avoid overflow.
   *
   */
  long a = 56789;
  long b = 23456789;
  long c = 0;
  c = a * b;
  std::cout << "56789*23456789=" << c << std::endl;
  return 0;
}