#include "vector_dot.h"

void allocVector(myVector* vec, int size)
{
  vec->length = size;
  vec->data   = (double*)malloc(sizeof(double) * size);
  memset(vec->data, 0, sizeof(double)*size);
}

void allocVector(myVector* vec, double* data, int size)
{
  vec->length = size;
  vec->data   = (double*)malloc(sizeof(double) * size);
  memcpy(vec->data, data, size);
}