#ifndef MAIN_H
#define MAIN_H

#include <sys/time.h>

#include "vector_dot.h"

double benchmark_millis(myVector *v1, myVector *v2, void (*dotProduct)(myVector *, myVector *));

#endif // MAIN_H