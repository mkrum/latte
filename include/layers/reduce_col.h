#ifndef REDUCE_COL_H
#define REDUCE_COL_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

class Reduce_Col : public Layer {
  public:
    Reduce_Col(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &forward(vector<Matrix> &);
  private:  
    Matrix data;
    char op;
};

#endif
