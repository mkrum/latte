#include "matrix.h"
#include "activations.h"
#include <iostream>
#include <cstddef>


int main() {
	double arr[] = { 1.0, 2.0, 3.0, 
		         4.0, 5.0, 6.0 };
	double w[] = { 2.0,
		       3.0};
	Matrix test(2, 3, arr);
	Matrix weights(3, 1, w);
	Matrix eq;
       	eq	= test;
	std::cout << test;
	std::cout << eq;
	std::cout << test * weights;
	std::cout << test % weights;
	std::cout << (test.activate(act::sigmoid));
	std::cout << test - 0.5;
	return 0;
}
