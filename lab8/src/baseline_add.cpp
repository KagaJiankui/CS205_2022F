#include "addvector.h"

#pragma optimize("O0")
void vectorAdd(const myVector &vecA, const myVector &vecB, myVector &vec_result) {
  if (vecA.length != vecB.length) {
    printf("Vector length mismatch");
  } else {
    vec_result.length = vecA.length;
    for (int i = 0; i < vecA.length; i++) {
      vec_result.data[i] = vecA.data[i] + vecB.data[i];
    }
  }
}