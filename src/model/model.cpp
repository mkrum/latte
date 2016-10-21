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

void Model::add_data_layer(std::string path, bool random) {
  Data *test = new Data(path, random);
  layers.push_back(test);
}

