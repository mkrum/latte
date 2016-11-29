#ifndef DATA_H
#define DATA_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;

class Data : public Layer {
  public:
    Data(string, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
    string name;
    Layer *prev;
    Layer *next;
  private:  
    Matrix data;
    string path;
};

#endif
