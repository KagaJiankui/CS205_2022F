#include <iostream>

#include "add.h"
int main() {
  int num1 = 2147483647;
  int num2 = 1;
  /**
  ********BUG REVIEW*********
  The maximum of the INT variable on 64-bit systems is $2^31-1=2147483647$.
  Thus the variable ``num1`` reaches the upper bond of the INT variable,
  adding this variable with any other nonzero variables leads to overflow.
  */

  long result = 0;
  result = add_long((long)num1, (long)num2);
  std::cout << "The result is " << result << std::endl;
  return 0;
}
