#include "layers/concat.h"

Concat::Concat(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  constant = std::atof(in_args[1].c_str());
}

Matrix &Concat::forward(Matrix &inputs) {    
  return inputs;
}

Matrix &Concat::forward(vector<Matrix> & inputs) {
  vector<size_t> new_shape;
  size_t min_len = -1;
  for (int i = 0; i < inputs.size(); i++) {
    if (inputs[i].shape[0] < min_len) {
      min_len = inputs[i].shape[0];
    }
    new_shape[1] += inputs[i].shape[1];
  }
  size_t new_size = min_len * inputs[0].shape[1];
  Matrix new_matrix(new_shape);

  for(int i = 0; i < inputs.size(); i++) {
    std::copy(inputs[i].data, inputs[i].data + new_size, new_matrix.data + i * new_size);
  }
  inputs[0].data = new_matrix.data;
  inputs[0].shape = new_matrix.shape;

  return inputs[0];
}
