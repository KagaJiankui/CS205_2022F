#ifndef EXERCISE2_H
#define EXERCISE2_H

#include <iostream>
#include <typeinfo>
using namespace std;
class Base {
protected:
  int bvalue;

public:
  Base(int i) : bvalue(i) {}
  virtual bool equal(const Base &b) const;
  friend bool  operator==(const Base &, const Base &);
};

class Derived : public Base {
private:
  int dvalue;

public:
  Derived(int a, int b) : Base(a), dvalue(b) {}
  bool equal(const Base &b) const override;
};

#endif // EXERCISE2_H