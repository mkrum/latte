#include <layers/debug.h>

Debug::Debug() { }

Matrix Debug::forward(Matrix test) {
  double *get = test(0);
  *get = *get * 2;
  return test;
}
