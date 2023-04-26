#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>
// #include <cmath>

class Complex {
private:
  double realPart;
  double imagPart;

public:
  Complex();
  Complex(double re);
  Complex(double re, double im);
  Complex &operator=(const Complex &operand);
  double   real() const { return this->realPart; }
  double   imag() const { return this->imagPart; }

public:
  friend Complex operator+(const Complex &operand1, const Complex &operand2);
  friend Complex operator-(const Complex &operand1, const Complex &operand2);
  friend Complex operator*(const Complex &operand1, const Complex &operand2);
  friend Complex operator/(const Complex &operand1, const Complex &operand2);
  friend Complex operator==(const Complex &operand1, const Complex &operand2);
  friend Complex operator!=(const Complex &operand1, const Complex &operand2);
  friend std::ostream &operator<<(std::ostream &out, Complex &A);
  friend std::istream &operator>>(std::istream &in, Complex &A);

  ~Complex() = default;
};

#endif // MYCOMPLEX_H