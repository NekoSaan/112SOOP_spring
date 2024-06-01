/************************************************************************
File:
		Polynomial.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/03
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/04
Description:
		implement a class called Polynomial to handle one-dimensional
		polynomials. This class needs to be able to store the coefficients
		and implement operations such as addition, subtraction,
		multiplication, and assignment.
************************************************************************/
#include "Polynomial.h"
#include <algorithm>
#include <cmath>
using namespace std;

// Default Constructor
Polynomial::Polynomial() {
	coefficient = new double(0.0);
}

// Destructor
Polynomial::~Polynomial() {
	delete[] coefficient;
	coefficient = nullptr;
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial& poly) {
	this->~Polynomial(); // clear original coefficients
	size = poly.size;

	coefficient = new double[size] {}; // initialize the coe array

	// Copying
	for (int i = 0; i < poly.size; i++) {
		coefficient[i] = poly.coefficient[i];
	}
}

// Assign Constructor
Polynomial::Polynomial(double* param, int size) {
	coefficient = new double[size] {}; // resize the array
	this->size = size;

	// Copying from parameters
	for (int i = 0; i < size; i++) {
		coefficient[i] = param[i];
	}
}

// Plus operator
const Polynomial Polynomial::operator+(const Polynomial& poly) {
	Polynomial result; // tmp
	int maxSize = std::max(size, poly.size);

	result.size = maxSize;
	result.coefficient = new double[result.size]{}; // initialize the coe array
	
	for (int i = 0; i < maxSize; i++) {
		result.coefficient[i] = ((i < size) ? coefficient[i] : 0) + ((i < poly.size) ? poly.coefficient[i] : 0);
	}

	result.clear_zero();

	return result;
}

// Substract operator
const Polynomial Polynomial::operator-(const Polynomial& poly) {
	Polynomial result;
	int maxSize = std::max(size, poly.size);

	result.size = maxSize;
	result.coefficient = new double[result.size]{}; 
	
	for (int i = 0; i < maxSize; i++) {
		result.coefficient[i] = ((i < size) ? coefficient[i] : 0) - ((i < poly.size) ? poly.coefficient[i] : 0);
	}

	result.clear_zero();

	return result;
}

// Multiplication Constructor
const Polynomial Polynomial::operator*(const Polynomial& poly) {
	Polynomial result;
	result.size = size + poly.size - 1;
	result.coefficient = new double[result.size]{0}; // initialize the coe array

	// compute the multi
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < poly.size; j++) {
			result.coefficient[i + j] += coefficient[i] * poly.coefficient[j];
		}
	}

	return result;
}

// search value by index, [] operator
double& Polynomial::operator[](int index) {
	if (index >= size) {
		Polynomial poly;

		poly.coefficient = new double[index + 1]{};

		for (int i = 0; i < size; i++) {
			poly.coefficient[i] = coefficient[i];
		}

		poly.size = index + 1;

		*this = poly;
	}

	return coefficient[index];
}

// Intent: To calculate the polynomial number given by value
// Pre: Target polynomial and value -> f(x)
// Post: The function returns result computation
// \param poly : The target polynomial function you want to compute
// \param var : The value of x -> f(x)
double evaluate(const Polynomial& poly, const double& var) {
	double result = 0.0;

	for (int i = 0; i < poly.size; i++) {
		result += (poly.coefficient[i] * pow(var, i));
	}

	return result;
}

// Equal operator
Polynomial& Polynomial::operator=(const Polynomial& poly) {
	this->~Polynomial(); // clear original data
	size = poly.size;
	coefficient = new double[size] {}; // initialize the array

	// Copying data from R-Value
	for (int i = 0; i < size; i++) {
		coefficient[i] = poly.coefficient[i];
	}

	return *this;
}

// Plus operator
Polynomial operator+(Polynomial poly, const double& num) {
	poly.coefficient[0] += num;

	poly.clear_zero();

	return poly;
}

// Substract operator
Polynomial operator-(Polynomial poly, const double& num) {
	poly.coefficient[0] -= num;

	poly.clear_zero();
	
	return poly;
}

// Multiplication operator
Polynomial operator*(Polynomial poly, const double& num) {
	for (int i = 0; i < poly.size; i++) {
		poly.coefficient[i] *= num;
	}

	poly.clear_zero();

	return poly;
}

// Plus operator
Polynomial operator+(const double& num, Polynomial poly) {
	poly.coefficient[0] += num;

	poly.clear_zero();

	return poly;
}

// Substarct operator
Polynomial operator-(const double& num, Polynomial poly) {
	poly = poly * (-1) + num;

	poly.clear_zero();

	return poly;
}

// Multiplication operator
Polynomial operator*(const double& num, Polynomial poly) {
	for (int i = 0; i < poly.size; i++) {
		poly.coefficient[i] *= num;
	}

	return poly;
}