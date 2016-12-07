#include "matrix.h"
#include <cstring>

#include <iostream>


Matrix::Matrix() : to_delete(false) { }

Matrix::Matrix(const Matrix &obj) {
  to_delete = false;
  data = obj.data;
  shape = obj.shape;
}

Matrix &Matrix::operator=(const Matrix &obj) {
  to_delete = false;
  data = obj.data;
  shape = obj.shape;
  return *this;
}

Matrix::Matrix(vector<size_t> dimensions) : shape(dimensions) {
  total_size = 1;
  for (auto d : dimensions) {
    total_size *= d;
  }

  //buffer space to keep things a bit
  data = new double[total_size];
  to_delete = true;

  //fill with sentinel values
  memset(data, -1.0, sizeof(*data));
}


//something about this feels dirty, but I think the scope will be okay
Matrix::Matrix(double *in_data, vector<size_t> in_shape) : shape(in_shape), data(in_data) {
  total_size = 1;
  for (size_t i = 0; i < shape.size(); i++) {
    total_size *= shape[i];
  }
  to_delete = false;
}


Matrix::~Matrix() {
  if (to_delete) {
    delete [] data;
  }
}


//get single value from dim
double &Matrix::get(vector<size_t> dim) {
  assert(dim.size() == shape.size());
  int index = 0;
  for(size_t i = 0; i < shape.size(); i++) {
    int adj = 1;

    for(int j = i - 1 ; j >= 0; j--) {
      adj = adj * shape[i]; 
    } 

    index += dim[i] * adj;
  }
  std::cout << index << " ";
  return data[index];
}


// needed only when "data" is private
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

  for (size_t i = 0; i < shape.size(); i++) {
    assert(shape[i] == other.shape[i]);
  }

  std::cout << shape[0] << " " << shape[1] << std::endl << other.shape[0] << " " << other.shape[1] << 
  std::endl;

  Matrix result(data, shape);

  for (size_t j = 0; j < total_size; j++) {
    result.set(j, data[j] + other.data[j]);
  }

  return result;
}


Matrix Matrix::operator+(double constant) {

  for(size_t i = 0; i < total_size; i++) {
    data[i] = data[i] + constant;
  }

  return *this;
}


Matrix Matrix::operator*(Matrix other) {
  assert (shape.size() == 2);
  assert (other.shape.size() == 2);
  assert (shape[1] == other.shape[0]);

  vector<size_t> new_shape;
  new_shape.push_back(shape[0]);
  new_shape.push_back(other.shape[1]);
  Matrix result(new_shape);

  for (size_t i = 0; i < shape[0]*other.shape[1]; i++) {
    double entry = 0;
    for (size_t j = 0; j < shape[1]; j++) {
      entry += data[(i/other.shape[1])*shape[1] + j]*other.data[i%other.shape[1] + other.shape[1]*j];
    }
    result.set(i, entry);
  }

  return result;
}


Matrix Matrix::operator*(double constant) {
  Matrix result(data, shape);

  for(size_t i = 0; i < total_size; i++) {
    result.data[i] = data[i] * constant;
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
