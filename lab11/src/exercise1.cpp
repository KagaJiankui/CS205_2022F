#include <iostream>
#include <memory>

using namespace std;
int main() {
  double            *p_reg = new double(5);
  shared_ptr<double> pd;
  // pd = p_reg;
  // bug at line 8: shared_ptr<T> cannot be constructed with operator=.
  pd = shared_ptr<double>(p_reg);
  cout << "*pd = " << *pd << endl;
  // shared_ptr<double> pshared = p_reg;
  // bug at line 12: shared_ptr<T> cannot be constructed with operator=.
  // shared_ptr<double> pshared(p_reg);
  shared_ptr<double> pshared;
  pshared = pd;
  // bug at line 14: initializing multiple shared_ptr<T> with the same nake pointer results in double free.
  cout << "*pshred = " << *pshared << endl;
  string             str("Hello World!");
  shared_ptr<string> pstr(&str);
  cout << "*pstr = " << *pstr << endl;
  return 0;
}