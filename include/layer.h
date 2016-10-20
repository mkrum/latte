#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"

class Layer {
  public:
    Layer() {};
    virtual ~Layer() { };
    virtual Matrix forward(Matrix) = 0;
};


#endif
