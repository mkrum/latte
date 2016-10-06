#include "model.h"

Model::Model() {
  for(int i = 0; i < layers.size(); i++) {
    delete layers[i];
  }
}

double Model::forward(double in) {
  return layers[0]->forward(in);
}

void Model::add_layer(std::string layer_name) {
  Debug *test = new Debug();
  layers.push_back(test);
}

