#include <cstddef>
struct MyMatrix
{
  float* mat;   // array of floats.
  size_t row;   // number of rows in the matrix.
  size_t col;   // number of columns in the matrix.

  float& operator()(int r, int c) { return mat[r * col + c]; }

  size_t length() { return row * col; }
};
MyMatrix allocMatrix(int row, int col);
void     freeMatrix(struct MyMatrix& matrix);
MyMatrix readMatFromFile(const char* filename);