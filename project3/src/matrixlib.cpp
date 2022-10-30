#include "matrixlib.h"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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
CMatrix CMatrix::eye(int l)
{
  CMatrix res(l, l);
  for (int i = 0; i < l; i++) {
    res.setElement(i, i, 1);
  }
  return res;
}
CMatrix::~CMatrix()
{
  if (this->data != NULL) {
    free(this->data);
    this->data = NULL;
  }
}
inline double CMatrix::getElement(int r, int c) const
{
  return this->data[r * this->col + c];
}
inline void CMatrix::setElement(int r, int c, double el)
{
  this->data[r * this->col + c] = el;
}
inline int CMatrix::getRows() const
{
  return this->row;
}
inline int CMatrix::getColumns() const
{
  return this->col;
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
// 将数组的值传递给矩阵(要求矩阵的大小已经被声明过了)
CMatrix& CMatrix::operator=(double* a)
{
  memcpy(this->data, a, col * row * sizeof(double));
  return *this;
}

bool CMatrix::operator==(const CMatrix& m) const
{
  if ((this->col != m.col) || (this->row != m.row)) {
    return 0;
  }
  else {
    for (int i = 0; i < (this->col) * (this->row); i++) {
      if (this->data[i] != m.data[i]) {
        return 0;
      }
    }
    return 1;
  }
}

CMatrix CMatrix::operator+(const CMatrix& m) const
{
  assert((this->col == m.col) && (this->row == m.row));
  CMatrix res(this->col, this->row);
  for (int i = 0; i < m.col * m.row; i++) {
    res.data[i] = this->data[i] + m.data[i];
  }
  return res;
}

CMatrix CMatrix::operator+(double a) const
{
  CMatrix res(*this);
  for (int i = 0; i < (this->col) * (this->row); i++) {
    res.data[i] += a;
  }
  return res;
}
CMatrix CMatrix::operator-(const CMatrix& m) const
{
  assert((this->col == m.col) && (this->row == m.row));
  CMatrix res(this->col, this->row);
  for (int i = 0; i < m.col * m.row; i++) {
    res.data[i] = this->data[i] - m.data[i];
  }
  return res;
}

CMatrix CMatrix::operator-(double a) const
{
  CMatrix res(*this);
  for (int i = 0; i < (this->col) * (this->row); i++) {
    res.data[i] -= a;
  }
  return res;
}
CMatrix CMatrix::operator*(const CMatrix& m) const
{
  assert(this->col == m.row);
  CMatrix res(this->row, m.col);
  double  v = 0;
  for (int i = 0; i < this->row; i++) {
    for (int k = 0; k < this->col; k++) {
      v = this->getElement(i, k);
      for (int j = 0; j < m.col; j++) {
        res.data[i * res.col + j] += v * m.getElement(k, j);
      }
    }
  }
  return res;
}
CMatrix CMatrix::operator*(double a) const
{
  CMatrix res(*this);
  for (int i = 0; i < (this->col) * (this->row); i++) {
    res.data[i] *= a;
  }
  return res;
}

double CMatrix::getMax(const CMatrix& m) const
{
  double tmp = this->data[0];
  for (int i = 0; i < (this->col * this->row); i++) {
    double r = this->data[i];
    tmp      = tmp < i ? i : tmp;
  }
  return tmp;
}
double CMatrix::getMin(const CMatrix& m) const
{
  double tmp = this->data[0];
  for (int i = 0; i < (this->col * this->row); i++) {
    double r = this->data[i];
    tmp      = tmp > i ? i : tmp;
  }
  return tmp;
}
CMatrix CMatrix::tr(const CMatrix& m)
{
  CMatrix res(m.col, m.row);
  for (int i = 0; i < m.row; i++) {
    for (int j = 0; j < m.col; j++) {
      res.setElement(j, i, m.getElement(i, j));
    }
  }
  return res;
}
void CMatrix::print(const CMatrix& m){
  for (int i = 0; i < m.row; i++)
  {
    for (int j = 0; j < m.col; j++)
    {
      printf("%.4f ", m.getElement(i, j));
    }
    printf("\n");
  }
}