/************************************************************************
File:
		main.cpp
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
#include<iostream>
#include "VecNf.h"
using namespace std;

int main() {
	VecNf empty;
	float a_value[] = { 3.0, 2.0 };
	float b_value[] = { 1, 2, 3 };
	float c_value[] = { 6, 5, 4 };
	VecNf A(a_value, 2);
	VecNf B(b_value, 3);
	VecNf C(c_value, 3);
	VecNf T;
	T = A; // Assignment
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;

	T = B; // Assignment
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;

	T = B + C; // Vector addition
	for (int i = 0; i < T.Size(); i++) {
		cout << T[i] << " ";
	} cout << endl;
	
	cout << C * B << endl; // Scale

	cout << A * C << endl; // Inconsistent

	return 0;
}