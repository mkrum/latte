#include "matrix.h"
#include "dense.h"
#include <iostream>


int main() {
	double arr[] = { 0.3, 0.4, 0.8 };
	double tar[] = { 0.5};
	Matrix test(1, 3, arr);
	Matrix target(1, 1, tar);
	Dense lay = Dense(3, 1);
	auto loss = [](double a, double b) { return (a - b) * (a - b); };
	for (int i = 0; i < 100; i++) {
		Matrix out = lay.feed_forward(test);
		Matrix error = compare(out, target, loss);
		lay.back_propagate(error);
		std::cout << lay.feed_forward(test);
		std::cout << std::endl;
	}

	return 0;
}
