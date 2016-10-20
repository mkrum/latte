#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <math.h>
#include <assert.h>
using std::vector;

class Matrix {

  public:
    Matrix();
    Matrix(vector<size_t>);
    Matrix(double *, vector<size_t>);
    double get(vector<size_t>);
    Matrix operator[](size_t);
    double *operator()(size_t);
  private:
    vector<size_t> shape;
    double *data;     
};


#endif
