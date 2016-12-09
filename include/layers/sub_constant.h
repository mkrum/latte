#ifndef SUB_CONSTANT_H
#define SUB_CONSTANT_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

class Sub_Constant : public Layer {
  public:
    Sub_Constant(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &forward(vector<Matrix> &);
  private:  
    Matrix data;
    double constant; 
};

#endif
