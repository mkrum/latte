#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <stack>

#include "matrix.h"
#include "layer.h"
#include "layers/data.h"
#include "layers/debug.h"
#include "layers/write.h"
#include "layers/add_constant.h"
#include "layers/sub_constant.h"
#include "layers/reduce_row.h"
#include "layers/reduce_col.h"
#include "layers/concat.h"

using std::string;

class Graph {
  public:
    Graph();
    ~Graph();
    void insert(string, string, vector<string>, vector<string>, vector<string>);
    Matrix forward();
    Matrix backward();
    void find_path(string);
  private:
    std::stack<string> curr_path;
    std::unordered_map<string, Layer* > directory;
    string output;
};

#endif
