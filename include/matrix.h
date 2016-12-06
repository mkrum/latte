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
    Matrix(const Matrix &);
    Matrix(vector<size_t>);
    Matrix(double *, vector<size_t>);
    ~Matrix();
    double &get(vector<size_t>);
    void set(size_t, double);
    Matrix operator[](size_t);
    double &operator()(size_t);
    Matrix operator+(Matrix);
    Matrix operator+(double);
    Matrix operator*(Matrix);
    Matrix operator*(double);
    Matrix &operator=(const Matrix &);
    Matrix cross(Matrix);
    vector<size_t> shape;
    double *data;
  private:
    size_t total_size;
    bool to_delete;
//    double *data;
};


#endif
