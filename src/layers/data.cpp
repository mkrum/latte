#include <layers/data.h>

Data::Data() { }

Matrix Data::csv_read(string path) {
  double *test_val = new double(1.2);
  vector<size_t> temp;
  temp.push_back(1);
  return Matrix(test_val, temp);    
}

Matrix Data::forward(Matrix inputs) {
  double *test_val = new double(1.2);
  vector<size_t> temp;
  temp.push_back(1);
  return Matrix(test_val, temp);    
}
