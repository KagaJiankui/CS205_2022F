#ifndef EXERCISE2_H
#define EXERCISE2_H

#include <exception>
#include <iostream>
class OutOfRangeException {
private:
  int pos;
  int iVal;

public:
  explicit OutOfRangeException(int _pos, int _iVal) : pos(_pos), iVal(_iVal) {}
  int getVal() const { return iVal; }
  int getPos() const { return pos; }
};

float calculateAverage(int *marks, int len);

#endif // EXERCISE2_H