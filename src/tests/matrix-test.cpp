#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	double data[4] = { 3, 1, 4, 0 };
	double data2[4] = { 2, 6, -2, 1.5 };
	vector<size_t> shape;
	shape.push_back(2);
	shape.push_back(2);

	Matrix test(data, shape);
	Matrix test2(data2, shape);

	test = test + test2;
	cout << test.data[0] << " " << test.data[1] << " " << test.data[2] << " " << test.data[3] << endl;

	test = test * 4.1;
	cout << test.data[0] << " " << test.data[1] << " " << test.data[2] << " " << test.data[3] << endl;

	test = test2 + test2;
	cout << test.data[0] << " " << test.data[1] << " " << test.data[2] << " " << test.data[3] << endl;

	test = test2 + 1.3;
	cout << test.data[0] << " " << test.data[1] << " " << test.data[2] << " " << test.data[3] << endl;
}
