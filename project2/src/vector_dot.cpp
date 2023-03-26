#include "vector_dot.h"

#include <exception>
#include <immintrin.h>
#include <iostream>
#include <stdexcept>

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

void copyVector(myVector *src, myVector *dst) {
    char length_flag = (char)((dst->length) >= (src->length) ? 1 : 0);
    dst->length      = src->length;
    if (length_flag) {
        memcpy(dst, src, sizeof(double) * src->length);
    } else {
        if (dst->data != nullptr) {
            free(dst->data);
            dst->data = nullptr;
        }
        dst->data = (double *)malloc(sizeof(double) * src->length);
        memcpy(dst, src, sizeof(double) * src->length);
    }
}

void modifyVector(myVector *vec, double *data_new, int size_new) {
    vec->length = size_new;
    if (vec->data != nullptr) {
        free(vec->data);
        vec->data = nullptr;
    }
    vec->data = (double *)malloc(sizeof(double) * size_new);
    memcpy(vec, data_new, sizeof(double) * size_new);
}

double dotProduct(myVector *v_1, myVector *v_2) {
    double result = 0;
    try {
        if (v_1->length != v_2->length) {
            throw std::out_of_range("Vector Length Mismatch");
        }
        int len = v_1->length;
        for (int i = 0; i < len; i++) {
            result += v_1->data[i] * v_2->data[i];
        }
        return result;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
}

double dotProduct_fast(myVector *v_1, myVector *v_2) {
    if (v_1->length != v_2->length) { // 检查长度是否一致
        throw std::invalid_argument("vector lengths do not match");
    }

    int     length = v_1->length;
    double *data_1 = v_1->data;
    double *data_2 = v_2->data;

    __m256d sum_vec = _mm256_setzero_pd(); // 初始化为0的256位寄存器

    for (int i = 0; i < length; i += 4) {
        // 从内存中加载4个双精度数到256位寄存器中
        __m256d vec_1 = _mm256_loadu_pd(&data_1[i]);
        __m256d vec_2 = _mm256_loadu_pd(&data_2[i]);
        // 生成掩码，将超出矢量长度的部分设为0
        __m256d mask = _mm256_cmp_pd(_mm256_set_pd(i + 3 > length, i + 2 > length, i + 1 > length, i > length), _mm256_setzero_pd(), _CMP_EQ_OQ);
        vec_1        = _mm256_and_pd(vec_1, mask);
        vec_2        = _mm256_and_pd(vec_2, mask);
        sum_vec      = _mm256_fmadd_pd(vec_1, vec_2, sum_vec);
        // 4个双精度数执行点乘并累加到256位寄存器中
    }

    double *sum_arr = (double *)&sum_vec;
    // 将256位寄存器中的双精度数转换为双精度数组
    double dot_product = sum_arr[0] + sum_arr[1] + sum_arr[2] + sum_arr[3];
    // 对双精度数组中的4个数求和得到点乘结果

    return dot_product;
}