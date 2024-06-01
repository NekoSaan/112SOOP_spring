/************************************************************************
File:
		VecNf.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/10
Description:
		Please define a class named VecNf to store a multidimensional
		vector and implement some simple vector operations.
************************************************************************/
#include "VecNf.h"

// Get dimension of the vector
int VecNf::Size(void) {
	return dim;
}

// Return value of the certain dimension in the vector
float& VecNf::operator[](const int index) {
	return elem[index];
}

// Assignment
VecNf& VecNf::operator=(const VecNf& v) {
	cout << "ASSIGNMENT!!!" << endl;

	elem.clear();
	dim = v.dim;

	for (int i = 0; i < dim; i++) {
		elem.push_back(v.elem[i]);
	}

	return *this;
}

// Addition
VecNf VecNf::operator+(const VecNf& v) {
	// checking two dim are same or not?
	if (dim != v.dim) {
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}

	VecNf newVec(*this);

	for (int i = 0; i < dim; i++) {
		newVec.elem[i] += v.elem[i];
	}

	return newVec;
}

// Substraction
VecNf VecNf::operator-(const VecNf& v) {
	// checking two dim are same or not?
	if (dim != v.dim) {
		cout << "dimensions inconsistent" << endl;
		return VecNf();
	}

	VecNf newVec(*this);

	for (int i = 0; i < dim; i++) {
		newVec.elem[i] -= v.elem[i];
	}

	return newVec;
}

// Inner product
float VecNf::operator*(const VecNf& v) {
	// checking two dim are same or not?
	if (dim != v.dim) {
		cout << "dimensions inconsistent" << endl;
		return 0;
	}

	float res = 0;

	for (int i = 0; i < dim; i++) {
		res += elem[i] * v.elem[i];
	}

	return res;
}

// Scale
VecNf operator*(const float num, const VecNf& v) {
	VecNf newVec(v);

	for (int i = 0; i < v.dim; i++) {
		newVec.elem[i] *= num;
	}

	return newVec;
}

// cout
ostream& operator<<(ostream& strm, const VecNf& v) {
	for (int i = 0; i < v.dim; i++) {
		strm << v.elem[i] << " ";
	}

	return strm;
}