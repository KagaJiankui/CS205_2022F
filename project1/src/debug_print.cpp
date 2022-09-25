#include "debug_print.h"

void debug_print(std::smatch exponentialMatcher)
{
  for (auto str_matched : exponentialMatcher) {
    std::cout << "Match result:" << str_matched;
    if (str_matched=="\0") {
      std::cout << "no result";
    }
    std::cout<<std::endl;
  }
  std::cout << std::endl;
}