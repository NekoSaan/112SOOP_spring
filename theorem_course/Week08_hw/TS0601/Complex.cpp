/************************************************************************
File:
		Complex.cpp
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
#include "Complex.h"

// Get real part
double Complex::real(void) {
	return realValue;
}

double real(Complex c) {
	return c.realValue;
}

// Get image part
double Complex::imag(void) {
	return image;
}

double imag(Complex c) {
	return c.image;
}

// Get normalize part
double Complex::norm(void) {
	return sqrt(pow(realValue, 2) + pow(image, 2));
}

double norm(Complex c) {
	return sqrt(pow(c.realValue, 2) + pow(c.image, 2));
}

// operators overloading
// two complex numbers
Complex Complex::operator+(Complex c) {
	return Complex(realValue + c.realValue, image + c.image);
}

Complex Complex::operator-(Complex c) {
	return Complex(realValue - c.realValue, image - c.image);
}

Complex Complex::operator*(Complex c) {
	return Complex(realValue * c.realValue - image * c.image, realValue * c.image + image * c.realValue);
}

Complex Complex::operator/(Complex c) {
	Complex conjugate(c.realValue, -c.image);
	Complex res = *this * conjugate;

	return res / (pow(c.realValue, 2) + pow(c.image, 2));
}

// complex number (+, -, *, /) real number
Complex Complex::operator+(double d) {
	return Complex(d + realValue, image);
}

Complex Complex::operator-(double d) {
	return Complex(realValue - d, image);
}

Complex Complex::operator*(double d) {
	return Complex(d * realValue, d * image);
}

Complex Complex::operator/(double d) {
	return Complex(realValue / d, image / d);
}

// real (+, -, *, /) a complex number
Complex operator+(double d, Complex c) {
	return Complex(d + c.realValue, c.image);
}

Complex operator-(double d, Complex c) {
	return Complex(d - c.realValue, -c.image);
}

Complex operator*(double d, Complex c) {
	return Complex(d * c.realValue, d * c.image);
}

Complex operator/(double d, Complex c) {
	Complex conjugate(c.realValue, -c.image);
	
	return d * conjugate / (pow(c.realValue, 2) + pow(c.image, 2));
}

// equivalent check
bool operator==(Complex c1, Complex c2) {
	return (c1.realValue == c2.realValue && c1.image == c2.image);
}

// cout
ostream& operator<<(ostream& strm, const Complex& c) {
	strm << c.realValue << " + " << c.image << "*i";
	return strm;
}

// cin
istream& operator>>(istream& strm, Complex& c) {
	strm.ignore(4);
	strm >> c.realValue;
	strm.ignore(3);
	strm >> c.image;
	strm.ignore(2);

	return strm;
}