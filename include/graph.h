#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
  
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
    void set_out(string);
  private:
    std::map<string, Layer *> directory;
    std::map<string, vector<Layer *> > paths;  
    string output;
};

#endif
