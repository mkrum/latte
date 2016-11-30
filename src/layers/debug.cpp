#include "layers/debug.h"

Debug::Debug(string in_name, vector<string> in, vector<string> out, vector<string> in_args) : name(in_name), prev(in), next(out) { }


Matrix &Debug::forward(Matrix &inputs) {
  if (inputs.shape.size() < 3) {
    for (int i = 0; i < inputs.shape[0]; i++) {
      for (int j = 0; j < inputs.shape[1]; j++) {
        std::cout << std::setprecision(5) << inputs[i](j) << " ";
      }
      std::cout << std::endl;
    }
  } else {
    std::cout << "Multi-dimensional output is not avaiable";
  }
  return inputs;
}

Matrix &Debug::backward(Matrix &inputs) {
  return inputs;
}
