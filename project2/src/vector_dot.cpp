#include "vector_dot.h"

#include <exception>
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
        free(vector);
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
