#include <iomanip>
#include <iostream>
int main() {
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  float a = 0.1, b = 0.2, c = 0.3;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
}