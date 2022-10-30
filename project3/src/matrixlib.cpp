#include "matrixlib.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

CMatrix::CMatrix(int col_num, int row_num)
{
  col  = col_num;
  row  = row_num;
  data = (double*)malloc(col * row * sizeof(double));
  memset(data, 0, col * row * sizeof(double));
}
CMatrix::CMatrix(int col_num, int row_num, double elem)
{
  col  = col_num;
  row  = row_num;
  data = (double*)malloc(col * row * sizeof(double));
  memset(data, (int)elem, col * row * sizeof(double));
}
CMatrix::CMatrix(int col_num, int row_num, double* arr, int len)
{
  col  = col_num;
  row  = row_num;
  data = (double*)malloc(col * row * sizeof(double));
  memset(data, 0, col * row * sizeof(double));
  if (col * row > len) {
    memcpy(data, arr, len * sizeof(double));
  }
  else {
    memcpy(data, arr, col * row * sizeof(double));
  }
}
CMatrix::~CMatrix()
{
    if (this->data != NULL) {
      free(this->data);
      this->data = NULL;
    }
}
double CMatrix::getElement(int r, int c) const
{
  return this->data[r * this->col + c];
}
void CMatrix::setElement(int r, int c, double el)
{
  this->data[r * this->col + c] = el;
}


CMatrix& CMatrix::operator=(const CMatrix& m)
{
  if (this == &m) {
    return *this;
  }
  this->col = m.col;
  this->row = m.row;
  free(this->data);
  this->data = (double*)malloc(m.col * m.row * sizeof(double));
  memcpy(this->data, m.data, m.col * m.row * sizeof(double));
  return *this;
}
//将数组的值传递给矩阵(要求矩阵的大小已经被声明过了)
CMatrix& CMatrix::operator=(double* a)
{
  memcpy(this->data, a, col * row * sizeof(double));
  return *this;
}