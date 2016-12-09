#include "graph.h"

Graph::Graph () {
  directory = {};
}

void Graph::insert(string s_type, string s_name, vector<string> inputs, vector<string> outputs, vector<string> in_args) {
  Layer * new_layer = nullptr;
  if (s_type.compare("debug") == 0) {
    new_layer = new Debug(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("data") == 0) {
    new_layer = new Data(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("write") == 0) {
    new_layer = new Write(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("add_constant") == 0) {
    new_layer = new Add_Constant(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("sub_constant") == 0) {
    new_layer = new Sub_Constant(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("reduce_row") == 0) {
    new_layer = new Reduce_Row(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("reduce_col") == 0) {
    new_layer = new Reduce_Col(s_name, inputs, outputs, in_args);
  } else if (s_type.compare("output") == 0) {
    new_layer = new Reduce_Col(s_name, inputs, outputs, in_args);
  } else {
    throw std::runtime_error("Undefined Layer");
  }

  
  directory.insert(std::make_pair(new_layer->name, new_layer));

}

void Graph::find_path(string in_path) {
   
  std::stack<string> top_sort;
  std::stack<string> frontier;

  frontier.push(in_path);

  while(!frontier.empty()) {
    string curr = frontier.top();
    if (directory.find(curr) == directory.end()) {
      throw std::runtime_error("Misnamed Variable");
    }
    frontier.pop();
    vector<string> next = directory[curr]->prev;
    for(int i = 0; i < next.size(); i++) {
      if(next[i].compare("NULL") != 0) {
        frontier.push(next[i]);
      }
    }
    top_sort.push(curr);
  }
  
  curr_path = top_sort;

}

Matrix Graph::forward() {
  std::stack<string> path_cpy = curr_path;

  std::stack<Matrix> buffer;
  Layer *curr_layer = nullptr;
  string curr;

  while(!path_cpy.empty()) {
    curr = path_cpy.top();
    path_cpy.pop();
    curr_layer = directory[curr];
    Matrix out;
   
    if (curr_layer->prev.size() == 1) {
      out = curr_layer->forward(out);
    } else if (curr_layer->prev.size() == 2) {
      out = buffer.top();
      buffer.pop();
      out = curr_layer->forward(out);
    } else if (curr_layer->prev.size() > 2) {
      out = buffer.top();
      buffer.pop();
      buffer.pop();
      out = curr_layer->forward(out);
    }

    buffer.push(out);

  }

  return buffer.top();
}

Graph::~Graph() {
  vector<string> names;
  for(std::unordered_map<string, Layer *>::iterator it = directory.begin();
    it != directory.end(); ++it) {
     names.push_back(it->first);
  }

  for(int i = 0; i < names.size(); i++) {
    delete directory[names[i]];
  }
}
