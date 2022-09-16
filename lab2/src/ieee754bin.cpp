#include <iostream>

void printFloat(float num) {
  int inum = *(int*)&num;
  for (int i = 0; i < 32; ++i) {
    std::cout << ((inum & 0x80000000) ? 1 : 0);
    if (i == 0 || i == 8) std::cout << " ";
    inum <<= 1;
  }
  std::cout << std::endl;
}

int main() {
  float f1 = 1.0;
  std::cout << "f1 = " << f1 << std::endl;
  std::cout << "The binary presentaion of f1"
            << " is:" << std::endl;
  printFloat(f1);
  std::cout << std::endl;

  float a = 0.1;
  float f2 = a + a + a + a + a + a + a + a + a + a;
  std::cout << "f2 = " << f2 << std::endl;
  std::cout << "The binary presentaion of f2"
            << " is:" << std::endl;
  printFloat(f2);
  std::cout << std::endl;

  return 0;
}
