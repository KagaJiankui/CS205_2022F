#include <iostream>
class Complex {
private:
  double realPart;
  double imagPart;

public:
  Complex();
  Complex(double re, double im);
  Complex     operator+(const Complex &operand);
  Complex     operator-(const Complex &operand);
  static void display(const Complex &operand);
  ~Complex() = default;
};
Complex::Complex() : realPart(0.0), imagPart(0.0) {}
Complex::Complex(double re, double im) : realPart(re), imagPart(im) {}
Complex Complex::operator+(const Complex &operand) {
  Complex res;
  res.realPart = this->realPart + operand.realPart;
  res.imagPart = this->imagPart + operand.imagPart;
  return res;
}
Complex Complex::operator-(const Complex &operand) {
  Complex res;
  res.realPart = this->realPart - operand.realPart;
  res.imagPart = this->imagPart - operand.imagPart;
  return res;
}
void Complex::display(const Complex &operand) { std::cout << operand.realPart << "+" << operand.realPart << "i" << std::endl; }

int main(int argc, char const *argv[]) {
  Complex c1 = Complex(1.0, 3.0);
  Complex c2 = Complex(2.0, -2.0);
  Complex::display(c1 + c2);
  Complex::display(c1 - c2);
  return 0;
}
