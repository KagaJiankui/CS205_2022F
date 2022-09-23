#include "fac.h"
#include <cstdio>
#pragma clang optimize on

using namespace std;
const int Max = 8000;
int res[Max];
double extra[10000];
int factorial_arb(int n) {
  extra[0] = 0;
  for (int i = 1; i <= 10000; i++) extra[i] = extra[i - 1] + log10(i);
    memset(res, 0, sizeof(res));
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
      int x = (int)extra[i] + 1;
      for (int j = 0, carry = 0; j <= x / 5; j++) {
        res[j] = res[j] * i + carry;
        carry = res[j] / 100000;
        res[j] %= 100000;
      }
    }
    int i = (int)extra[n] + 1;
    for (i = i / 5; i >= 0; i--) {
      if (res[i]) break;
    }
    printf("%d", res[i--]);
    for (int j = i; j >= 0; j--) {
      printf("%05d", res[j]);
    }
    printf("\n");
  return 0;
}