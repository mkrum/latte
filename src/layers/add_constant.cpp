#include "layers/add_constant.h"

Add_Constant::Add_Constant(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  constant = std::atof(in_args[1].c_str());
}

Matrix &Add_Constant::forward(Matrix &inputs) {    
  inputs + constant;
  return inputs;
}

Matrix &Add_Constant::forward(vector<Matrix> & inputs) {    
  return inputs[0];
}
