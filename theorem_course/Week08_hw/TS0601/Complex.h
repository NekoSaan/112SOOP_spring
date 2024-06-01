/************************************************************************
File:
		Complex.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/10
Description:
		Define a class for complex numbers named Complex. A complex number
		is a number formed as  a + b * i, where a and b are numbers of type
		double, and i is a number that represents the quantity กิ(-1).
************************************************************************/
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

// Complex number Class
class Complex
{
public:
	double realValue, image;

	// Default Constructor
	Complex() : realValue(0), image(0) {};
	Complex(double r) : realValue(r), image(0) {};
	Complex(double r, double i) : realValue(r), image(i) {};

	// Destructor
	~Complex() {
		realValue = 0;
		image = 0;
	}

	// Return Value of complex number
	double real(void);
	double imag(void);
	double norm(void);

	friend double real(Complex c);
	friend double imag(Complex c);
	friend double norm(Complex c);	
	
	// operators overloading
	// two complex numbers
	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);

	// complex number (+, -, *, /) real number
	Complex operator+(double d);
	Complex operator-(double d);
	Complex operator*(double d);
	Complex operator/(double d);

	// real number (+, -, *, /) complex number
	friend Complex operator+(double d, Complex c);
	friend Complex operator-(double d, Complex c);
	friend Complex operator*(double d, Complex c);
	friend Complex operator/(double d, Complex c);

	// equivalent
	friend bool operator==(Complex c1, Complex c2);	

	// cout
	friend ostream& operator<<(ostream &strm, const Complex &c);

	// cin
	friend istream& operator>>(istream &strm,Complex &c);
};

#endif // _COMPLEX_H_