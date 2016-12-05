#include "graph.h"
#include <set> // not sure if added in graph.h or not


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
	Layer * curr = directory.find[in_path]; 	// finds the current layer in dir - currently getting error
	vector<string> previous = curr->prev; // finds what the layer depends on
	vector<string> curr_string; 		// transforms the in_path into a vector string
	curr_string.push_back(in_path);

	set<string> visited;

	vector< vector<std::shared_ptr<Layer> > > path; // the path that will be returned
	path.push_back(curr_string); 			// pushes back the root node first
	visited.insert(curr_string);

	path.push_back(previous); 			// pushes back the next layers (dependencies)

	/*
	for(it = 0; it < previous.size(); it++){
		find_path_r(previous[i], path, visited); // recursively call find path
		visited.insert(curr_string);
	}
	*/

	return path;

}

void Graph::find_path_r(string in_path, vector<vector<std::shared_ptr<Layer> > > path, set<string> visited) {
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

