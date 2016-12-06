#include "layers/data.h"

Data::Data(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  path = in_args[1];
  width = std::atoi(in_args[2].c_str());
  length = std::atoi(in_args[3].c_str());
  delim = *in_args[4].c_str();  

}

Matrix &Data::forward(Matrix &inputs) {    

  vector<size_t> shape;
  shape.push_back(width);
  shape.push_back(length);
  data = Matrix(shape);

  std::ifstream file_(path.c_str());
  string line;

  for (size_t i = 0; i < length; i++) {
    for (size_t j = 0; j < width - 1; j++) {
      std::getline(file_, line, delim);
      data.get({ i , j }) = std::atof(line.c_str());
      std::cout << std::atof(line.c_str()) << " ";
    }
    std::getline(file_, line);
    data.get({i, width}) = std::atof(line.c_str());
    std::cout << std::atof(line.c_str()) << " ";
    std::cout << std::endl;
  }

  file_.close();

  return data;
}

Matrix &Data::backward(Matrix &inputs) {    
  return inputs;
}
