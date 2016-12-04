#include "layers/debug.h"

Debug::Debug(string in_name, vector<string> in, vector<string> out, vector<string> in_args) {
  name = in_name;
  prev = in; 
  next = out;
}


Matrix &Debug::forward(Matrix &inputs) {
  std::cout << name << std::endl;
  return inputs;
}

Matrix &Debug::backward(Matrix &inputs) {
  return inputs;
}
