#include <iostream>
int main(int argc, char const* argv[])
{
  int* arr1 = new int[5]{1, 2, 3, 4, 5};
  int  len  = 5;
  for (char i = len - 1; i >= 0; i--) {
    std::cout << "Element " << i << " = " << *(arr1 + i) << std::endl;
  }
  delete[] arr1;
  return 0;
}
