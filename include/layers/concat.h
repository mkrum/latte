#ifndef DEBUG_H
#define DEBUG_H

#include "../layer.h"
#include "../matrix.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip> 

using std::string;
using std::vector;

class Concat : public Layer {
  public:
    Concat(string, vector<string>);
    Matrix &forward(Matrix&);
    Matrix &backward(Matrix&);
    string name;
    string next;
    string prev;
  private:  
    
};

#endif
