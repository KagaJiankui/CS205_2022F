#include "myComplex.h"
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  Complex c1 = Complex(1, 2);
  std::cin >> c1;
  Complex c2 = Complex(-1, 0.3);
  Complex c3;
  c3 = c1 + c2;
  cout << "c1 + c2 = " << c3 << endl;
  c3 = c1 - c2;
  cout << "c1 - c2 = " << c3 << endl;
  c3 = c1 * c2;
  cout << "c1 * c2 = " << c3 << endl;
  c3 = c1 / c2;
  cout << "c1 / c2 = " << c3 << endl;
  return 0;
}
