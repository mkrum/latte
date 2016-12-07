#ifndef ADD_CONSTANT_H
#define ADD_CONSTANT_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

class Add_Constant : public Layer {
  public:
    Add_Constant(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
  private:  
    Matrix data;
    double constant; 
};

#endif
