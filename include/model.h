#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "layer.h"
#include <layers/debug.h>
#include <layers/data.h>

class Model {
  public:
    Model();
    Matrix forward();
    void add_layer(std::string);
  private:
    std::vector<Layer*> layers;
};

#endif
