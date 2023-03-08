#ifndef MAIN_H
#define MAIN_H

#include "vector_dot.h"
#include <sys/time.h>

double benchmark_millis(myVector* v1, myVector* v2, void (*dotProduct)(myVector*, myVector*));

#endif   // MAIN_H