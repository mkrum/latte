#include "layers/reduce_col.h"

Reduce_Col::Reduce_Col(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  op = *in_args[1].c_str();
}

Matrix &Reduce_Col::forward(Matrix &inputs) {    
  Matrix reduced({ inputs.shape[1] });
  
  for (size_t i = 0; i < inputs.shape[0]; i++) {
    double col = inputs.get({0, i});
    for (size_t j = 0; j < inputs.shape[1]; j++) {
      switch (op){
        case '+':
          col += inputs.get({j, i});
          break;
        case '-':
          col -= inputs.get({j, i});
          break;
        case '*':
          col *= inputs.get({j, i});
          break;
        case '/':
          col /= inputs.get({j, i});
          break;
      }
    }
    std::cout << col << " ";
    reduced.get({ i }) = col;

  }

  inputs.data = reduced.data;
  inputs.shape = reduced.shape;
  return inputs;
}

Matrix &Reduce_Col::forward(vector<Matrix> & inputs) {    
  return inputs[0];
}
