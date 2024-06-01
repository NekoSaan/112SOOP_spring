/************************************************************************
File:
		Polynomial.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/03
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/03
Description:
		implement a class called Polynomial to handle one-dimensional
		polynomials. This class needs to be able to store the coefficients
		and implement operations such as addition, subtraction,
		multiplication, and assignment.
************************************************************************/
#pragma once

class Polynomial {
private:
	double* coefficient = nullptr;
	int size = 0;

public:
	// Default Constructor
	Polynomial();

	// Destructor
	~Polynomial();

	// Copy Constructor
	Polynomial(const Polynomial&);

	// Assign Constructor
	Polynomial(double*, int);

	// Operators overload
	const Polynomial operator+(const Polynomial&);
	const Polynomial operator-(const Polynomial&);
	const Polynomial operator*(const Polynomial&);
	Polynomial& operator=(const Polynomial&);
	double& operator[](int);

	// evaluate function
	friend double evaluate(const Polynomial&, const double&);

	// mySize function, return size
	int mySize() {
		return size;
	}

	// Constructor when encounter constant value
	friend Polynomial operator+(Polynomial poly, const double& num);
	friend Polynomial operator-(Polynomial poly, const double& num);
	friend Polynomial operator*(Polynomial poly, const double& num);

	friend Polynomial operator+(const double& num, Polynomial poly);
	friend Polynomial operator-(const double& num, Polynomial poly);
	friend Polynomial operator*(const double& num, Polynomial poly);

	// clear all zero
	void clear_zero() {
		for (int i = size - 1; !coefficient[i]; i--, size--);
	}
};