#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

typedef struct {
  int     length;
  double *data;
} myVector;

void allocVector(myVector *vec, int size);
void allocVector(myVector *vec, double *data, int size);
void freeVector(myVector *vector);
void printVector(myVector *v);
void AllocRandtoVector(myVector *vector, double randmax);