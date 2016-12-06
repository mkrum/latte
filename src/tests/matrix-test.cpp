#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	double data[4] = { 3.6, -2.7, 0.3, 1.9 };
	double data2[6] = { -4.5, -0.7, 2.1, 1.2, -3.3, 2 };

	vector<size_t> shape;
	shape.push_back(2);
	shape.push_back(2);
	Matrix test(data, shape);

	shape.pop_back();
	shape.pop_back();
	shape.push_back(2);
	shape.push_back(3);
	Matrix test2(data2, shape);

	Matrix test4 = test * test2;
	cout << test4.data[0] << " " << test4.data[1] << " " << test4.data[2] << " " << test4.data[3] <<
	" " << test4.data[4] << " " << test4.data[5] << endl;
}
