#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
  
#include "matrix.h"
#include "layer.h"
#include "layers/data.h"
#include "layers/debug.h"

using std::string;

class Graph {
  public:
    Graph();
    void insert(string, string, vector<string>, vector<string>, vector<string>);
    Matrix forward();
    Matrix backward();
    void set_out(string);
  private:
    vector<vector<std::shared_ptr<Layer> > > curr_path;
    vector<vector<std::shared_ptr<Layer> > > find_path(string);
    std::unordered_map<string, Layer* > directory;
    std::unordered_map<string, vector<std::shared_ptr<Layer> > > paths;  
    void find_path(string, vector<vector<std::shared_ptr<Layer> > >, vector<string>);
    string output;
};

#endif
