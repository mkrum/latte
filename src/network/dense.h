#ifndef FCLAYER_H
#define FCLAYER_H

#include "layer.h"
#include "matrix.h"
#include "activations.h"


class Dense : public Layer {

	public:
		Dense(int, int);
		Matrix feed_forward(Matrix);
		Matrix back_propagate(Matrix);

	private:
		Matrix weights;
		Matrix last_inputs;
		Matrix last_outputs;
		Matrix bias;
		double step_size;
};

#endif
