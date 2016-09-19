#import "matrix.h"

sim-outorder –config sa1core.cfg fooMatrix::Matrix() {
	height =  0;
	width  =  0;
	data = new double[1];
	data[0] = 0.0;
}

Matrix::Matrix(size_t in_h, size_t in_w, double *array) {
	height =  in_h;
	width  =  in_w;

	data = new double[height * width + 1];
	memcpy(data, array, height * width * sizeof(double));

}

Matrix::Matrix(size_t in_h, size_t in_w) {
	height =  in_h;
	width  =  in_w;
	data   =  new double[height * width + 1];

	for (int i = 0; i < height * width; i++){
		data[i] = 0.0;
	}
}

Matrix::Matrix(size_t in_h, size_t in_w, double low, double high) {
	height =  in_h;
	width  =  in_w;
	data   =  new double[height * width + 1];

	std::default_random_engine generator;
       	std::uniform_real_distribution<double> distribution(low, high);

	for (int i = 0; i < height * width; i++){
		data[i] = distribution(generator);
	}
}

Matrix::Matrix(const Matrix &copy){
	height = copy.height;
	width = copy.width;
	double *temp = new double[height * width + 1];
	memcpy(temp, copy.data, height * width * sizeof(double));
	data = temp;
}

Matrix::Matrix(Matrix && move){
	height = move.height;
	width = move.width;
	data   =  new double[height * width + 1];
	memcpy(data, move.data, height * width * sizeof(double));
	move.data = nullptr;
}

Matrix &Matrix::operator =(const Matrix &copy) {
	if(this != &copy) {
		height = copy.height;
		width = copy.width;
		double *temp = new double[copy.height * copy.width + 1];
		memcpy(temp, copy.data, height * width * sizeof(double));
		delete [] data;
		data = temp;
	}

	return *this;
}

Matrix &Matrix::operator =(Matrix &&move) {
	height =  move.height;
	width  =  move.width;
	delete [] data;
	data      =  move.data;
	move.data =  nullptr;
	return *this;
}

double Matrix::operator ()(size_t i, size_t j) const {
	return data[j + i * width];
}

double & Matrix::operator ()(size_t i, size_t j) {
	return data[j + i * width];
}

double Matrix::operator [](size_t i) const {
	return data[i];
}

double & Matrix::operator [](size_t i) {
	return data[i];
}

Matrix Matrix::transpose() {
	int temp = height;
	height = width;
	width = temp;
	return *this;
}

double *Matrix::row(size_t r) const {
	double *row_vals = new double[width];

	for (int i = 0; i < width; i++) {
		row_vals[i] = data[i + r * width];
	}
	return row_vals;
}

double *Matrix::col(size_t c) const {
	double *col_vals = new double[height];

	for (int i = 0; i < height; i++) {
		col_vals[i] = data[c + i * width];
	}
	return col_vals;
}

Matrix Matrix::activate(std::function<double(double)> activation) {

	Matrix result(height, width, data);
	result.modify(activation);
	return result;

}

Matrix Matrix::modify(std::function<double(double)> modification) {

	for (int i = 0; i < height * width; i++) {
		data[i] = modification(data[i]);

	}
	return *this;

}

int Matrix::h() const {
	return height;
}

int Matrix::w() const {
	return width;
}



std::ostream& operator <<(std::ostream& os, const Matrix &m1) {
	for (int j = 0; j < m1.h(); j++) {
		for (int i = 0; i < m1.w(); i++) {
			os << m1(j, i) << ' ';
		}
		os << '\n';
	}
	return os;
}

//restricitons: m1.w() == m2.h()
Matrix operator %(const Matrix &m1, const Matrix &m2) {
	Matrix result(m1.h(), m2.w());
	for (int i = 0; i < m1.h(); i++) {
		double *row = m1.row(i);
		for (int j = 0; j < m1.w(); j++) {
			double *col = m2.col(j);
			double acc = 0.0;
			for (int k = 0; k < m1.w(); k++) {
				acc += row[k] * col[k];
			}
			result(i, j) = acc;
		}
	}
	return result;
}
//ERROR CHECKING MUST BE SAME SIZE
Matrix operator +(const Matrix &m1, const Matrix &m2) {
	Matrix result(m1.h(), m1.w());
	for (int i = 0; i < m1.w() * m1.h(); i++) {
		result.data[i] = m2.data[i] + m1.data[i];
	}

	return result;
}

Matrix operator -(const Matrix &m1, const Matrix &m2) {
	if (m2.is_row()) {
		Matrix result(m1.h(), m1.w());
		for (int i = 0; i < m1.h(); i++) {
			for (int j = 0; j < m1.w(); j++) {
				result(i, j) = m1(i, j) - m2(i, 0);
			}
		}
		return result;
	} else {
		Matrix result(m1.h(), m1.w());
		for (int i = 0; i < m1.w() * m1.h(); i++) {
			result.data[i] = m2.data[i] - m1.data[i];
		}
		return result;
	}
}

Matrix operator *(const Matrix &m1, double ch) {
	Matrix result(m1.h(), m1.w(), m1.data);
	auto delta = [ch](double in) -> double {
		return in * ch;
	};
	return result.activate(delta);
}

Matrix operator +(const Matrix &m1, double ch) {
	Matrix result(m1.h(), m1.w(), m1.data);
	auto delta = [ch](double in) -> double {
		return in + ch;
	};
	return result.activate(delta);
}

Matrix operator -(const Matrix &m1, double ch) {
	Matrix result(m1.h(), m1.w(), m1.data);
	auto delta = [ch](double in) -> double {
		return in - ch;
	};
	return result.activate(delta);
}
//restrictions: m2 needs to be m.w() by 1
Matrix operator *(const Matrix &m1, const Matrix &m2) {
	Matrix result = m1;
	for (int i = 0; i < m1.h(); i++) {
		for (int j = 0; j < m1.w(); j++) {
			result(i, j) = result(i, j) * m2(i, 0);
		}
	}
	return result;
}

//ADD ERROR checking
Matrix compare(const Matrix &m1, const Matrix &m2, std::function<double(double, double)> comp) {
	Matrix result(m1.h(), m1.w(), m1.data);
	for (int i = 0; i < m1.h() * m1.w(); i++) {
		result.data[i] = comp(m1.data[i], m2.data[i]);
	}
	return result;
}

bool Matrix::is_row() const {
	return width == 1;
}

bool Matrix::is_col() const {
	return height == 1;
}
