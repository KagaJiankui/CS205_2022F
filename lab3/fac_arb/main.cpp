#include <iostream>

#include "fac.h"

int main(int argc, const char** argv) {
  int n = 0;
  while (1) {
    std::cout << "Please input a positive integer:";
    std::cin >> n;
    if (n > 0) {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << i << "!=";
    factorial_arb(i);
  }
  std::cout << std::endl;
  return 0;
}