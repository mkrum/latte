#include "layers/data.h"

Data::Data(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  path = in_args[1];
  
  size_t width = std::atoi(in_args[2].c_str());
  size_t length = std::atoi(in_args[3].c_str());
  char delim = *in_args[4].c_str();  
  std::cout << length << std::endl;
  std::cout << width << std::endl;
  std::cout << delim << std::endl;
  vector<size_t> shape;
  shape.push_back(width);
  shape.push_back(length);
  data = Matrix(shape);

  std::ifstream file(path.c_str());
  string line;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width - 1; j++) {
      std::getline(file, line, delim);
      data[i](j) = std::atof(line.c_str());
      std::cout << data[i](j) << " ";
    }
    std::getline(file, line);
    data[i](width) = std::atof(line.c_str());
    std::cout << data[i](width) << " ";
    std::cout << std::endl;
  }
}

Matrix &Data::forward(Matrix &inputs) {    
  return data;
}

Matrix &Data::backward(Matrix &inputs) {    
  return inputs;
}
