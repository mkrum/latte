#include "layers/data.h"

//DEBUGGING
#include <iostream>
using std::cout;

Data::Data(string in_name, vector<string> in_args) : name(in_name), path(in_args[2])  {
  size_t width = std::atoi(in_args[3].c_str());
  size_t length = std::atoi(in_args[4].c_str());
  vector<size_t> shape;
  shape.push_back(width);
  shape.push_back(length);
  data = Matrix(shape);

  char delim = *in_args[3].c_str();  
  std::ifstream file(path.c_str());
  string line;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      std::getline(file, line, delim);
      data[i](j) = std::atof(line.c_str());
    }
  }
}

Matrix &Data::forward(Matrix &inputs) {    
  return data;
}

Matrix &Data::backward(Matrix &inputs) {    
  return inputs;
}
