#include "fib.h"
#include <climits>

long fib(int n) {
  long f[3]={0,1,0};
  if ((n == 0) || (n == 1)) {
    return 1;
  }else {
    for (long i = 0; i < n; i++) {
      *(f + 2) = *f + *(f + 1);
      *(f) = *(f + 1);
      *(f + 1) = *(f + 2);
      if (*(f+2)>=LONG_MAX)
      {
        return -1;
      }
    }
    return *(f + 2);
  }
}