#include "layers/sub_constant.h"

Sub_Constant::Sub_Constant(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in;
  next = out;
  constant = std::atof(in_args[1].c_str());
}

Matrix &Sub_Constant::forward(Matrix &inputs) {    
  inputs - constant;
  return inputs;
}

Matrix &Sub_Constant::backward(Matrix &inputs) {    
  return inputs;
}
