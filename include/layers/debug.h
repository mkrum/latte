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

class Debug : public Layer {
  public:
    Debug(string, vector<string>, vector<string>,vector<string>);
    Matrix &forward(Matrix&);
    Matrix &forward(vector<Matrix> &);
  private:  
    
};

#endif
