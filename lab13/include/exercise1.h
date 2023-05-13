#ifndef EXERCISE1_H
#define EXERCISE1_H

#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair;
template <class T1, class T2>
bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs);
template <class T1, class T2>
ostream &operator<<(ostream &os, const Pair<T1, T2> &p);

/*https://blog.csdn.net/Draonly/article/details/115590684 解决模板类外定义模板运算符重载的问题*/
/*https://blog.csdn.net/huanghxyz/article/details/85280144 解决模板类外定义模板成员函数的问题*/

template <class T1, class T2>
class Pair {
public:
  T1 key;
  T2 value;

  Pair(T1 k, T2 v) : key(k), value(v) {}
  friend bool     operator< <T1,T2>(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs);
  friend ostream &operator<< <T1,T2>(ostream &os, const Pair<T1, T2> &p);
};
template <class T1, class T2>
bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs) {
  return lhs.key < rhs.key;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const Pair<T1, T2> &p) {
  os << p.key << "    " << p.value;
  return os;
}

#endif // EXERCISE1_H