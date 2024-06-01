/************************************************************************
File:
		VecNf.h
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
#ifndef _VECNF_H_
#define _VECNF_H_
#include <iostream>
#include <vector>

using namespace std;

// VecNf class
class VecNf {
private:

public:
	vector<float> elem;
	int dim;

	// Default Constructor
	VecNf() {
		elem.push_back(0);
		dim = 1;
	}

	// Assign Constructor
	VecNf(float* dest, int cnt) {
		for (int i = 0; i < cnt; i++) {
			elem.push_back(dest[i]);
		}

		dim = cnt;
	}

	// Copy Constructor
	VecNf(const VecNf& rhs) {
		this->~VecNf();
		
		for (int i = 0; i < rhs.dim; i++) {
			elem.push_back(rhs.elem[i]);
		}

		dim = rhs.dim;
	}

	// Destructor
	~VecNf() {
		elem.clear();
		dim = NULL;
	}

	// Get dimension of the vector
	int Size(void);

	// operators Overloading
	// Return value of the certain dimension in the vector
	float& operator[](const int index);

	// Assignment
	VecNf& operator=(const VecNf& v);

	// Addition
	VecNf operator+(const VecNf& v);

	// Substraction
	VecNf operator-(const VecNf& v);

	// Inner product
	float operator*(const VecNf& v);

	// Scale
	friend VecNf operator*(const float num, const VecNf& v);

	// cout
	friend ostream& operator<<(ostream& strm, const VecNf& v);
};
#endif // _VECNF_H_