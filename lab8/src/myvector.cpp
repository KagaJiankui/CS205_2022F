#include "myvector.h"

void allocVector(myVector *vec, int size) {
  vec->length = size;
  vec->data   = (double *)malloc(sizeof(double) * size);
  memset(vec->data, 0, sizeof(double) * size);
}

void allocVector(myVector *vec, double *data, int size) {
  vec->length = size;
  vec->data   = (double *)malloc(sizeof(double) * size);
  memcpy(vec->data, data, sizeof(double) * size);
}

void freeVector(myVector *vector) {
  if (vector != nullptr) {
    if (vector->data != nullptr) {
      free(vector->data);
      vector->data   = nullptr;
      vector->length = 0;
    }
    // free(vector);
    vector = nullptr;
  }
}

void printVector(myVector *v) {
  for (int i = 0; i < v->length; i++) {
    printf("%.2f ", v->data[i]);
    if ((i % 8 == 1) && (i > 1)) {
      printf("\n");
    }
  }
  printf("\n");
}

void AllocRandtoVector(myVector *vector, double randmax) {
  std::srand(std::time(nullptr));
  for (int i = 0; i < vector->length; i++) {
    vector->data[i] = (std::rand() - RAND_MAX / 2) / ((1.0 + RAND_MAX) / randmax);
  }
}