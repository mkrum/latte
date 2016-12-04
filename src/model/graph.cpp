#include "graph.h"

Graph::Graph() : directory(), paths() { 

}

void Graph::insert(string s_type, string s_name, vector<string> inputs, vector<string> outputs, vector<string> in_args) {

  Layer * new_layer = nullptr;
  if (s_type.compare("debug") == 0) {
    new_layer = new Debug(s_name, inputs, outputs, in_args);
  }
  else if (s_type.compare("data") == 0) {
    new_layer = new Data(s_name, inputs, outputs, in_args);
  }
  
  directory[new_layer->name] = new_layer;
}

// FIND PATH FUCTION HERE
vector<vector<std::shared_ptr<Layer> > > Graph::find_path(string in_path) {
  vector< vector<std::shared_ptr<Layer> > > path;

  return path;
}

Matrix Graph::forward() {
  return Matrix();
}

void Graph::set_out(string in_out) { 
  if(paths.find(in_out) != paths.end()) {
 //   curr_path = paths[in_out];
  } else  {
  //  paths[in_out] = find_path(in_out);
  }
}

