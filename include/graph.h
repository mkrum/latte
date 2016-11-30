#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>
  
#include "matrix.h"
#include "layer.h"

using std::string;

class Graph {
  public:
    Graph();
    ~Graph();
    void insert(string, Layer *);
    Matrix forward();
    Matrix backward();
  private:
    std::map<string, Layer *> directory;
};

#endif
