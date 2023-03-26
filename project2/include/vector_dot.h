#ifndef VECTOR_DOT_H
#define VECTOR_DOT_H
#include <cstdlib>
#include <cstring>

#define VEC_LEN_MISMATCH 2
#define ALLOC_FAIL       3
#define FREE_FATL        4
#define MALLOC_FAIL      5

typedef struct {
    double *data;
    int     length;
} myVector;

void   allocVector(myVector *vec, int size);
void   allocVector(myVector *vec, double *data, int size);
void   freeVector(myVector *vector);
void   copyVector(myVector *src, myVector *dst);
void   modifyVector(myVector *vec, double *data_new, int size_new);
double dotProduct(myVector *v_1, myVector *v_2);
double dotProduct_fast(myVector *v_1, myVector *v_2);

#endif // VECTOR_DOT_H