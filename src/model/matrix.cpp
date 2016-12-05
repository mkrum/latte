#include "matrix.h"
#include <cstring>

Matrix::Matrix() { }


Matrix::Matrix(vector<size_t> dimensions) : shape(dimensions) {
  size_t total_size = 1;
  for (auto d : dimensions) {
    total_size *= d;
  }

  data = new double[total_size];

  //fill with sentinel values
  memset(data, -1.0, total_size*sizeof(double));
}


//something about this feels dirty, but I think the scope will be okay
Matrix::Matrix(double *in_data, vector<size_t> in_shape) : shape(in_shape), data(in_data) { }


//get single value from dim
double &Matrix::get(vector<size_t> dim) {
  assert(dim.size() == shape.size());
  int index = 0;
  for(int i = 0; i < shape.size(); i++) {
    index += dim[i] * pow(shape[i], i);
  }
  return data[index];
}


void Matrix::set(size_t index, double value) {
  data[index] = value;
}

Matrix Matrix::operator[](size_t index) {
  //do bound checking at some point

  vector<size_t> new_shape(shape.size() - 1);
  for (size_t i = 0; i < shape.size() - 1; i++) {
    new_shape[i] = shape[i];
  }

  if (shape.size() == 1) {
    new_shape.push_back(1);
  }

  return Matrix(&operator()(index), new_shape); //Matrix(operator()(index), shape);
}


double &Matrix::operator()(size_t index) {
  //do bound checking at some point
  int slice = 0;
  int size = shape.size();
  slice = index * pow(shape[size - 1], size - 1);
  return data[slice];
}


Matrix Matrix::operator+(Matrix other) {
  assert (shape.size() == other.shape.size());

  size_t total_size = 1;
  for (size_t i = 0; i < shape.size(); i++) {
    assert(shape[i] == other.shape[i]);
    total_size *= shape[i];
  }

  Matrix result(data, shape);

  for (size_t j = 0; j < total_size; j++) {
    result.set(j, data[j] + other.data[j]);
  }

  return result;
}


Matrix Matrix::operator*(Matrix other) {
  assert (shape.size() == other.shape.size());

  size_t total_size = 1;
  for (size_t i = 0; i < shape.size(); i++) {
    assert(shape[i] == other.shape[i]);
    total_size *= shape[i];
  }

  Matrix result(data, shape);

  for (size_t j = 0; j < total_size; j++) {
    result.set(j, data[j] * other.data[j]);
  }

  return result;
}


Matrix Matrix::cross(Matrix other) {
  assert (shape.size() == 1);
  assert (shape[0] == 3);
  assert (other.shape.size() == 1);
  assert (other.shape[0] == 3);

  Matrix result(data, shape);

  result.set(0, data[1]*other.data[2] - data[2]*other.data[1]);
  result.set(1, data[0]*other.data[2] - data[2]*other.data[0]);
  result.set(2, data[0]*other.data[1] - data[1]*other.data[0]);

  return result;
}
