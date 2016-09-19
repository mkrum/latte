#include "dense.h"

Dense::Dense(int n_in, int n_out) : weights(n_in, n_out, 0.0, 1.0), bias(n_out, 1, 0.0, 0.1), step_size(.09) {  }

Matrix Dense::feed_forward(Matrix inputs) {
	last_inputs = inputs;
	last_outputs = (inputs % weights).activate(act::sigmoid);
	return last_outputs;
}

Matrix Dense::back_propagate(Matrix error) {
	Matrix delta = last_inputs * last_outputs.activate(act::sigmoid_der) * error;
	std::cout << delta;
	std::cout << std::endl;
	weights = weights - delta;
	std::cout << weights;
	return error;
}

