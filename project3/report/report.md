# Project 3 Report

Author:Qiu Kunyuan [11913019](mailto://11913019@mail.sustech.edu.cn)

## C++ Struct design

A matrix class `CMatrix` is designed to store the key values and row major data of the matrix.

``` mermaid
classDiagram
class CMatrix
CMatrix : -int row
CMatrix : -int col
CMatrix : -double* data
CMatrix : CMatrix&       operator=(const CMatrix&)
CMatrix : CMatrix&       operator=(double*)
CMatrix : CMatrix        operator+(const CMatrix& m) const
CMatrix : CMatrix        operator+(const double a) const
CMatrix : CMatrix        operator-(const CMatrix& m) const
CMatrix : CMatrix        operator-(const double a) const
CMatrix : CMatrix        operator*(const CMatrix& m) const
CMatrix : CMatrix        operator*(const double a) const
CMatrix : bool           operator==(const CMatrix& m) const
CMatrix : int            getRows() const
CMatrix : int            getColumns() const
CMatrix : double         getMin(const CMatrix& m) const
CMatrix : double         getMax(const CMatrix& m) const
CMatrix : inline double  getElement(int r, int c) const
CMatrix : inline void    setElement(int r, int c, double el)
CMatrix : CMatrix        getRowVector(int r) const
CMatrix : CMatrix        getColVector(int c) const
CMatrix : static void    print(const CMatrix&)
CMatrix : static CMatrix eye(int)
CMatrix : static CMatrix tr(const CMatrix&)
```

where the overloaded operators are equivalent to the copy and scalar operation and linear matrix operation and matrix multiplication.

## Function and Opeartor Lists

### Constructors

This library provides 4 methods of construction. The first method is create a matrix filled by zero, which is equivalent to the MATLAB `zeros()`.

```cpp
CMatrix::CMatrix(int col_num, int row_num)
{
  col  = col_num;
  row  = row_num;
  data = (double*)malloc(col * row * sizeof(double));
  memset(data, 0, col * row * sizeof(double));
}
```