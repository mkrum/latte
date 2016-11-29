#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include <string>
#include <vector>

class Layer {
  public:
    Layer() {};
    virtual ~Layer() { };
    virtual Matrix &forward(Matrix &) = 0;
    virtual Matrix &backward(Matrix &) = 0;
    std::string name;
    Layer *next;
    Layer *prev;
  private:

};

#endif
