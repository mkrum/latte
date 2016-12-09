#ifndef CONCAT_H
#define CONCAT_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

class Concat : public Layer {
  public:
    Concat(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &forward(vector<Matrix> &);
  private:  
    Matrix data;
    double constant; 
};

#endif
