#include "layers/output.h"

Output::Output(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  path = in_args[1];
}

Matrix &Output::forward(Matrix &inputs) {    
  std::ofstream f(path);

	if (!f.good())
	{
		std::cout << "Error opening file" << std::endl;
	}

  if (inputs.shape.size() < 3) {
    for (size_t i = 0; i < inputs.shape[1]; i++) {
      for (size_t j = 0; j < inputs.shape[0]; j++) {
        f << inputs.get({i, j}) << " ";
      }
      f << std::endl;
    }
  } else {
    std::cout << "Multi-dimensional output is not avaiable";
  }
  f.close();
  return inputs;
}

Matrix &Output::backward(Matrix &inputs) {    
  return inputs;
}
