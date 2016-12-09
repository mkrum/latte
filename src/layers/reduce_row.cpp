#include "layers/reduce_row.h"

Reduce_Row::Reduce_Row(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  op = *in_args[1].c_str();
}

Matrix &Reduce_Row::forward(Matrix &inputs) {    
  vector<double> rows; 
  for (size_t i = 0; i < inputs.shape[1]; i++) {
    double row = inputs.get({i, 0});
    for (size_t j = 1; j < inputs.shape[0]; j++) {
      switch (op){
        case '+':
          row += inputs.get({i, j});
          break;
        case '-':
          row -= inputs.get({i, j});
          break;
        case '*':
          row *= inputs.get({i, j});
          break;
        case '/':
          row /= inputs.get({i, j});
          break;
      }
    }
    rows.push_back(row);
  }

  inputs.shape = { 1, inputs.shape[1] };
  for (size_t i = 0; i < rows.size(); i++) {
    inputs.get({i, 0}) = rows[i];
  }

  return inputs;
}

Matrix &Reduce_Row::forward(vector<Matrix> & inputs) {    
  return inputs[0];
}
