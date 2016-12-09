#ifndef WRITE_H
#define WRITE_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

class Write : public Layer {
  public:
    Write(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &forward(vector<Matrix> &);
  private:  
    string path;
};

#endif
