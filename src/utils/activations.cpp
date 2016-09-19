#include "activations.h"
#include "matrix.h"
#include <math.h>

namespace act {

	double sigmoid(double val) {
		return 1 / (1 + exp(-val));
	}

	double sigmoid_der(double val) {
		return sigmoid(val) * (1 - sigmoid(val));
	}

	double relu(double val) {
		if (val < 0) {
			return 0;
		} else {
			return val;
		}
	}
}

