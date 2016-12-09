#include "layers/output.h"

Output::Output(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
}

Matrix &Output::forward(Matrix &inputs) {
  if (inputs.shape.size() == 2) {
    for (size_t i = 0; i < inputs.shape[1]; i++) {
      for (size_t j = 0; j < inputs.shape[0]; j++) {
        cout << inputs.get({i, j}) << " ";
      }
      cout << std::endl;
    }
  } else if (inputs.shape.size() == 1) {
     for(size_t i = 0; i < inputs.shape[0]; i++) {
        cout << inputs.get({ i }) << std::endl;
     }
  } else {
    cout << "Multi-dimensional output is not avaiable" << std::endl;
  }

  return inputs;
}

Matrix &Output::backward(Matrix &inputs) {
  return inputs;
}
