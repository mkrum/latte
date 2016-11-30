#include "graph.h"

Graph::Graph() { }

void Graph::insert(string in_name, Layer * new_layer) {
  directory[in_name] = new_layer;
}

void Graph::set_out(string in_out) { 
     
}

Graph::~Graph() {
  std::map<string, Layer *>::iterator it;
  for (it = directory.begin(); it != directory.end(); it++) {
    delete it->second;  
  }
}
