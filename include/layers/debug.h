#ifndef DEBUG_H
#define DEBUG_H

#include "../layer.h"
#include "../matrix.h"

class Debug : public Layer {
  public:
    Debug();
    Matrix forward(Matrix);
  private:  
};

#endif
