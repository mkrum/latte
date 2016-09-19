#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstddef>
#include <random>

using std::size_t;


class Matrix {

	public:
		Matrix();
		Matrix(size_t, size_t);
		Matrix(size_t, size_t, double *);
		Matrix(size_t, size_t, double, double);
		Matrix(const Matrix &);
		Matrix(Matrix &&);

		Matrix &operator =(const Matrix &);
		Matrix &operator =(Matrix &&);

		virtual ~Matrix() { delete [] data; };
		
		double operator ()(size_t, size_t) const;
		double & operator ()(size_t, size_t);

		double operator [](size_t) const;
		double & operator [](size_t);

		int w() const;
		int h() const;

		bool is_row() const;
		bool is_col() const;

		double *row(size_t) const;
		double *col(size_t) const;

		Matrix activate(std::function<double(double)>); 
		Matrix modify(std::function<double(double)>);
		
		Matrix transpose();

		void copy(Matrix &);

		friend std::ostream& operator <<(std::ostream& os, const Matrix &m1);

		friend Matrix operator %(const Matrix &m1, const Matrix &m2);
		friend Matrix operator *(const Matrix &m1, const Matrix &m2);
		friend Matrix operator +(const Matrix &m1, const Matrix &m2);
		friend Matrix operator -(const Matrix &m1, const Matrix &m2);

		friend Matrix operator *(const Matrix &m1, double ch);
		friend Matrix operator +(const Matrix &m1, double ch);
		friend Matrix operator -(const Matrix &m1, double ch);
		
		friend Matrix compare(const Matrix &, const Matrix &, std::function<double(double, double)>);

	private:
		int height;
		int width;
		int dims;
		double *data;

};
				

#endif
