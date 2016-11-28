#ifndef DATA_H
#define DATA_H

#include "../layer.h"
#include "../matrix.h"
#include <string>

using std::string;

class Data : public Layer {
  public:
    Data(string);
    Matrix forward(Matrix);
  private:  
    Matrix data;
    string path;
};

#endif
