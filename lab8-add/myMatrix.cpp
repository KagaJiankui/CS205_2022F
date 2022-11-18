#include "myMatrix.h"
#include <cstdio>
#include <cstdlib>
MyMatrix allocMatrix(int row, int col)
{
  struct MyMatrix result
  {};
  result.row = row;
  result.col = col;
  result.mat = (float*)malloc(sizeof(float) * row * col);

  return result;
}
void freeMatrix(struct MyMatrix& matrix)
{
  free(matrix.mat);
}
MyMatrix readMatFromFile(const char* filename)
{
  FILE* file = fopen(filename, "r");
  int   row = 0, col = 0;
  fscanf(file, "%d%d", &row, &col);
  MyMatrix result = allocMatrix(row, col);
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) { fscanf(file, "%f", &result(i, j));
}
}
  fclose(file);
  return result;
}
void writeMatToFile(MyMatrix& mat, const char* filename)
{
  FILE* file = fopen(filename, "w");
  fprintf(file, "%zu %zu\n", mat.row, mat.col);
  for (int i = 0; i < mat.row; ++i) {
for (int j = 0; j < mat.col; ++j) { fprintf(file, " %f", mat(i, j));
}
fprintf(file, "\n");
  }
  fclose(file);
}
