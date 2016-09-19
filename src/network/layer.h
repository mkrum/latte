#ifndef LAYER_H
#define LAYER_H

#include <iostream>
#include "matrix.h"

class Layer {
	public:
		virtual Matrix feed_forward(Matrix) = 0;
		virtual Matrix back_propagate(Matrix) = 0;
		virtual ~Layer() = default;
};

#endif
