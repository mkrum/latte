#include "layers/reduce_col.h"

Reduce_Col::Reduce_Col(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  op = *in_args[1].c_str();
}

Matrix &Reduce_Col::forward(Matrix &inputs) {    
  vector<double> cols; 
  for (size_t i = 0; i < inputs.shape[0]; i++) {
    double col = inputs.get({0, i});
    for (size_t j = 1; j < inputs.shape[1]; j++) {
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

    cols.push_back(col);
  }
  inputs.shape = { inputs.shape[0], 1};
  for (size_t i = 0; i < inputs.shape[0]; i++) {
    inputs.get({0, i}) = cols[i];
  }
  return inputs;
}

Matrix &Reduce_Col::forward(vector<Matrix> & inputs) {    
  return inputs[0];
}
