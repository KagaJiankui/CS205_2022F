#include <iostream>
#include <climits>

int main() {
  int max_int = INT_MAX,min_int=INT_MIN;
  std::cout << "The limit of the 32bit int in ILP64 machine is: [" << min_int
            << "," << max_int << "]" << std::endl;
  std::cout << "Upper overflow: " << max_int + 1 << std::endl;
  std::cout << "Under overflow: " << min_int - 1 << std::endl;
  return 0;
}