#ifndef DATA_H
#define DATA_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

class Data : public Layer {
  public:
    Data(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
  private:  
    Matrix data;
    string path;
    size_t width;
    size_t length;
    char delim;
};

#endif
