#include "debug_print.h"
#include <iostream>

void debug_print(std::smatch exponentialMatcher)
{
  for (auto str_matched : exponentialMatcher) {
    std::cout << "Match result:" << str_matched;
    if (str_matched == "\0") {
      std::cout << "no result";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void debug_print(std::vector<std::complex<double>>& complexVector)
{
  std::cout << "Value:" << std::endl;
  // int l = complexVector.size();
  for (int i = 0; i < complexVector.size(); ++i) {
    std::cout << complexVector[i];
    if (!((i+1) % 10)) {
      std::cout << std::endl;
    }
  }
  std::cout<<std::endl;
}