#ifndef __MATRIXLIB__H__
#define __MATRIXLIB__H__


class CMatrix
{
  private:
  int     col;
  int     row;
  double* data;

  public:
  CMatrix(int, int);
  CMatrix(int, int, double);
  CMatrix(int, int, double*, int);
  virtual ~CMatrix();
  CMatrix&       operator=(const CMatrix&);
  CMatrix&       operator=(double*);
  CMatrix        operator+(const CMatrix& m) const;
  CMatrix        operator+(const double a) const;
  CMatrix        operator-(const CMatrix& m) const;
  CMatrix        operator-(const double a) const;
  CMatrix        operator*(const CMatrix& m) const;
  CMatrix        operator*(const double a) const;
  bool           operator==(const CMatrix& m) const;
  int            getRows() const;
  int            getColumns() const;
  double         getMin(const CMatrix& m) const;
  double         getMax(const CMatrix& m) const;
  inline double  getElement(int r, int c) const;
  inline void    setElement(int r, int c, double el);
  CMatrix        getRowVector(int r) const;
  CMatrix        getColVector(int c) const;
  static void    print(const CMatrix&);
  static CMatrix eye(int);
  static CMatrix tr(const CMatrix&);
};
#endif   //!__MATRIXLIB__H__
