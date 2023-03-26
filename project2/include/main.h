#ifndef MAIN_H
#define MAIN_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

#include "vector_dot.h"

void   AllocRandtoVector(myVector *vector, double randmax);
double benchmark_millis(myVector *v1, myVector *v2, void (*dotProduct)(myVector *, myVector *));
void   printVector(myVector *v);

#endif // MAIN_H