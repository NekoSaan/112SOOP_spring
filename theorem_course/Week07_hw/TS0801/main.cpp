/************************************************************************
File:
		main.cpp
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
#include <iostream>
#include <string>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);

	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4); // c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q; // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	c[6] = 6;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}