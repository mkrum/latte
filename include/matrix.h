#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <math.h>
#include <assert.h>
#include <string>
#include <cstring>

using std::vector;

class Matrix {

  public:
    Matrix();
    Matrix(vector<size_t>);
    Matrix(double *, vector<size_t>);
    double &get(vector<size_t>);
    void set(size_t, double);
    Matrix operator[](size_t);
    double &operator()(size_t);
    Matrix operator+(Matrix);
    Matrix operator*(Matrix);
    Matrix cross(Matrix);
    vector<size_t> shape;
    double *data;
//  private:
//    double *data;
};


#endif
