#include <cmath>
#include <sys/time.h>

#include "addvector.h"

double benchmark_millis(myVector &v1, myVector &v2, void (*vectorAdd)(const myVector &, const myVector &, myVector &)) {
  struct timeval t1, t2;
  double         delta_time = 0;
  gettimeofday(&t1, nullptr);
  myVector vec_res;
  allocVector(&vec_res, v1.length);
  // std::cout<<vectorAdd(v1, v2)<<" ";
  vectorAdd(v1, v2, vec_res);
  gettimeofday(&t2, nullptr);
  delta_time = (t2.tv_sec - t1.tv_sec) * 1000.0 + (double)(t2.tv_usec - t1.tv_usec) / 1000.0;
  return delta_time;
}

void LargeRandTest(char max_test_size, int *size_list, double *test_result) {
  int *test_size_list = (int *)std::malloc(sizeof(int) * max_test_size);
  for (char i = 0; i < max_test_size; i++) {
    test_size_list[i] = std::pow(2, i) + (int)((std::rand() - RAND_MAX / 2) / (1.0f + RAND_MAX) * 8.2);
    size_list[i]      = test_size_list[i];
  }
  for (char i = 0; i < max_test_size; i++) {
    myVector vec1, vec2;
    allocVector(&vec1, test_size_list[i]);
    allocVector(&vec2, test_size_list[i]);
    AllocRandtoVector(&vec1, 2);
    AllocRandtoVector(&vec2, 2);
    test_result[i] = benchmark_millis(vec1, vec2, vectorAdd);
    freeVector(&vec1);
    freeVector(&vec2);
  }
}

int main(int  /*argc*/, char const * /*argv*/[]) {
  char   size            = 29;
  double result_list[29] = {};
  int    size_list[29]   = {};
  LargeRandTest(size, size_list, result_list);
  FILE *result_csv = fopen("./report/test_2^28_avx2_o3.csv", "w");
  for (char i = 0; i < size; i++) {
    fprintf(result_csv, "%d,", size_list[i]);
  }
  fprintf(result_csv, "\n");
  for (char i = 0; i < size; i++) {
    fprintf(result_csv, "%.4f,", result_list[i]);
  }
  fprintf(result_csv, "\n");
  fclose(result_csv);

  return 0;
}