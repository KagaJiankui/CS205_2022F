#include "exercise2.h"

bool operator==(const Base & op1, const Base & op2) {
  if (typeid(op1)!=typeid(op2))
  {
    throw new string("”The two objects have different types, they can not be compared.");
  }else
  {
    return op1.bvalue==op2.bvalue;
  }
}

bool Base::equal(const Base &b) const { return this->bvalue == b.bvalue; }

bool Derived::equal(const Derived &d) const {

}