#ifndef VECTOR_DOT_H
#define VECTOR_DOT_H
#include <cstdlib>
#include <cstring>

typedef struct
{
  double* data;
  int    length;
} myVector;

void allocVector(myVector* vec, int size);
void allocVector(myVector* vec, double* data, int size);
void freeVector(myVector* vector);
void copyVector(myVector* src, myVector* dst);
void modifyVector(myVector* vec, double* data_new, int size_new);
void dotProduct(myVector* v_1, myVector* v_2);
void dotProduct_fast(myVector* v_1, myVector* v_2);

#endif   // VECTOR_DOT_H