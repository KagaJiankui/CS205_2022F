#include "main.h"
#include "vector_dot.h"

double benchmark_millis(myVector* v1, myVector* v2, void (*dotProduct)(myVector*, myVector*))
{
  struct timeval t1, t2;
  double         delta_time = 0;
  gettimeofday(&t1, nullptr);
  dotProduct(v1, v2);
  gettimeofday(&t2, nullptr);
  delta_time = (t2.tv_sec - t1.tv_sec) * 1000.0 + (double)(t2.tv_usec - t1.tv_usec) / 1000.0;
  return delta_time;
}