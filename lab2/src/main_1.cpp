#include <iostream>

#include "mul.h"
using namespace std;
int main() {
  int a, b;
  int result;
  cout << "Pick two integers:";
  cin >> a >> b; // NOTE: the two `cin>>a` statement results in the variable
  // `a` becomes one single integer. And the variable `b` is not properly initialized.
  result = mul(a, b);
  cout << "The result is " << result << endl;
  return 0;
}
