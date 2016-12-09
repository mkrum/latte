#ifndef OUTPUT_H
#define OUTPUT_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

class Output : public Layer {
  public:
    Output(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
  private:

};

#endif
