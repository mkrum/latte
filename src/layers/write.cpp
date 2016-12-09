#include "layers/write.h"

Write::Write(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  path = in_args[1];
}

Matrix &Write::forward(Matrix &inputs) {    
  std::ofstream f(path);

	if (!f.good())
	{
		std::cout << "Error opening file" << std::endl;
	}

  if (inputs.shape.size() == 2) {
    for (size_t i = 0; i < inputs.shape[1]; i++) {
      for (size_t j = 0; j < inputs.shape[0]; j++) {
        f << inputs.get({i, j}) << " ";
      }
      f << std::endl;
    }
  } else if (inputs.shape.size() == 1) {
     for(size_t i = 0; i < inputs.shape[0]; i++) {
        f << inputs.get({ i }) << std::endl;
     } 
  } else {
    std::cout << "Multi-dimensional output is not avaiable";
  }
  f.close();
  return inputs;
}

Matrix &Write::backward(Matrix &inputs) {    
  return inputs;
}
