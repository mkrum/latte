#ifndef OUTPUT_H 
#define OUTPUT_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>

using std::string;
using std::vector;

class Output : public Layer {
  public:
    Output(string, vector<string>, vector<string>, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
    string name;
    vector<string> prev;
    vector<string> next;
  private:  
    string path;
};

#endif
