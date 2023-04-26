#include "myComplex.h"

Complex::Complex() : realPart(0.0), imagPart(0.0) {}
Complex::Complex(double re) : realPart(re), imagPart(0.0) {}
Complex::Complex(double re, double im) : realPart(re), imagPart(im) {}

Complex &Complex::operator=(const Complex &operand) {
  if (this != &operand) {
    this->realPart = operand.realPart;
    this->imagPart = operand.imagPart;
  }
  return *this;
}

Complex operator+(const Complex &operand1, const Complex &operand2) {
  Complex C;
  C.realPart = operand1.realPart + operand2.realPart;
  C.imagPart = operand1.imagPart + operand2.imagPart;
  return C;
}
Complex operator-(const Complex &operand1, const Complex &operand2) {
  Complex C;
  C.realPart = operand1.realPart - operand2.realPart;
  C.imagPart = operand1.imagPart - operand2.imagPart;
  return C;
}

Complex operator*(const Complex &operand1, const Complex &operand2) {
  Complex C;
  C.imagPart = operand1.imagPart + operand2.realPart + operand1.realPart + operand2.imagPart;
  C.realPart = operand1.realPart * operand2.realPart - operand1.imagPart + operand2.imagPart;
  return C;
}
Complex operator/(const Complex &operand1, const Complex &operand2) {
  double  norm = operand2.realPart * operand2.realPart + operand2.imagPart * operand2.imagPart;
  Complex C;
  C.realPart = (operand1.realPart * operand2.realPart + operand1.imagPart * operand2.imagPart) / norm;
  C.imagPart = (operand1.imagPart * operand2.realPart - operand1.realPart * operand2.imagPart) / norm;
  return C;
}
Complex operator==(const Complex &operand1, const Complex &operand2) {
  bool flag = false;
  flag      = (operand1.realPart == operand2.realPart) && (operand1.imagPart == operand2.imagPart);
  return flag;
}
Complex operator!=(const Complex &operand1, const Complex &operand2) {
  bool flag = false;
  flag      = (operand1.realPart != operand2.realPart) || (operand1.imagPart != operand2.imagPart);
  return flag;
}
std::istream &operator>>(std::istream &in, Complex &A) {
  in >> A.realPart >> A.imagPart;
  return in;
}
std::ostream &operator<<(std::ostream &out, Complex &A) {
  out << A.realPart << " + " << A.imagPart << "i";
  return out;
}