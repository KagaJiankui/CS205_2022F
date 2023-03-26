#include "main.h"

#include <cmath>
#include <cstdio>
#include <iostream>

#include "vector_dot.h"

double benchmark_millis(myVector *v1, myVector *v2, double (*dotProduct)(myVector *, myVector *)) {
    struct timeval t1, t2;
    double         delta_time = 0;
    gettimeofday(&t1, nullptr);
    // std::cout<<dotProduct(v1, v2)<<" ";
    dotProduct(v1, v2);
    gettimeofday(&t2, nullptr);
    delta_time = (t2.tv_sec - t1.tv_sec) * 1000.0 + (double)(t2.tv_usec - t1.tv_usec) / 1000.0;
    return delta_time;
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
        test_result[i] = benchmark_millis(&vec1, &vec2, dotProduct_fast);
        freeVector(&vec1);
        freeVector(&vec2);
    }
}

void BaseVmulTest() {
    myVector vec1, vec2;
    int      length        = 10;
    double   data_vec1[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
    double   data_vec2[10] = {2, 1, 2, 1, 4, 3, 4, 3, 4, 3};
    double   res           = 0;
    double   res_fast      = 0;
    allocVector(&vec1, data_vec1, length);
    allocVector(&vec2, data_vec2, length);
    res      = dotProduct(&vec1, &vec2);
    res_fast = dotProduct_fast(&vec1, &vec2);
    printf("Baseline: %.4f, AVX2 Optimized: %.4f, Difference: %.4f", res, res_fast, res - res_fast);
}

int main(int argc, char const *argv[]) {
    char   size            = 19;
    double result_list[19] = {};
    int    size_list[19]   = {};
    LargeRandTest(size, size_list, result_list);
    FILE *result_csv = fopen("./report/test_2^18_avx2.csv", "w");
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
