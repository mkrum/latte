#include "graph.h"

Graph::Graph() { }

void Graph::insert(string in_name, Layer *new_layer) {
  directory.insert(std::pair<string, Layer*> (in_name, new_layer));
}

// FIND PATH FUCTION HERE
vector<vector<Layer *> > Graph::find_path(string in_path) {
  vector< vector<Layer *> > path;

  return path;
}

Matrix Graph::forward() {

  if (curr_path.size() < 1) {
    return Matrix();
  }

  Matrix temp;
  for(int i = 0; i < curr_path.size(); i++) {
//    temp = curr_path[i].forward(temp);
  }
  return temp;

}

void Graph::set_out(string in_out) { 
  if(paths.find(in_out) != paths.end()) {
 //   curr_path = paths[in_out];
  } else  {
  //  paths[in_out] = find_path(in_out);
  }
}

Graph::~Graph() {
  std::map<string, Layer *>::iterator it;
  for (it = directory.begin(); it != directory.end(); it++) {
    delete it->second;  
  }
}
