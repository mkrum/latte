#include "model.h"

Model::Model() {
  for(int i = 0; i < layers.size(); i++) {
    delete layers[i];
  }
}

Matrix Model::forward() {
  Matrix inputs;
  for(int i = 0; i < layers.size(); i++) {
    inputs = layers[i]->forward(inputs);
  }
  return inputs;
}

void Model::add_layer(std::string layer_name) {
  if (layer_name.compare("debug") == 0) {
    Debug *test = new Debug();
    layers.push_back(test);
  } else {
    Data *test = new Data();
    layers.push_back(test);
  }
}

