#include <iomanip>
#include <iostream>
#include "fib.h"

int main(int argc, const char** argv) {
  int n = 0;
  long fib_res = 0;
  while (1) {
    std::cout << "Please input a positive integer:";
    std::cin >> n;
    if (n > 0) {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    fib_res = fib(i-1);
    std::cout << std::setw(8) << fib_res;
    if ((i%10==0)&&(i!=0))
    {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}