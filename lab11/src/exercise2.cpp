#include <iostream>
#include <memory>
class Matrix {
private:
  std::shared_ptr<float> data;
  int                    row;
  int                    column;
  int                    length;

public:
  Matrix(int row, int column);
  Matrix(const Matrix &A);
  ~Matrix();
  Matrix              &operator=(const Matrix &A);
  friend Matrix        operator+(const Matrix &A, const Matrix &B);
  friend std::ostream &operator<<(std::ostream &out, Matrix &A);
};

Matrix::Matrix(int row, int column) : row(row), column(column), length(row * column) {
  this->data = std::shared_ptr<float>(new float[length], [](const float *p) { delete[] p; });
}

Matrix::Matrix(const Matrix &A) : row(A.row), column(A.column), length(A.length) { this->data = std::shared_ptr<float>(A.data); }

Matrix &Matrix::operator=(const Matrix &A) {
  if (this != &A) {
    this->column = A.column;
    this->row    = A.row;
    this->length = A.length;
    this->data   = A.data;
  }
  return *this;
}

Matrix operator+(const Matrix &A, const Matrix &B) {
  if ((A.column != B.column) || (A.row != B.row)) {
    return A;
  } else {
    Matrix       res(A.row, A.column);
    float       *data_res = res.data.get();
    const float *data_A   = A.data.get();
    const float *data_B   = B.data.get();
    for (int i = 0; i < A.length; i++) {
      *(data_res + i) = *(data_A + i) + *(data_B + i);
    }
    return res;
  }
}

std::ostream &operator<<(std::ostream &out, Matrix &A) {
  float *data_ptr = A.data.get();
  for (int i = 0; i < A.row; i++) {
    for (int j = 0; j < A.column; j++) {
      std::cout << *(data_ptr + i * A.row + j) << "   ";
    }
    std::cout << std::endl;
  }
  return out;
}

Matrix::~Matrix() = default;

int main(int argc, char const *argv[]) {
  Matrix a(3, 4);
  Matrix b(3, 4);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  Matrix c = a + b;
  std::cout << c << std::endl;
  Matrix d = a;
  std::cout << d << std::endl;
  d = b;
  std::cout << d << std::endl;
  return 0;
}
