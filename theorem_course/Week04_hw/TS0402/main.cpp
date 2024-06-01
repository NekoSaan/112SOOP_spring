/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/12
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/12
Description:
		Define a class for a type called Fraction.This class is used to 
		represent a ratio of two integers.
************************************************************************/
#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2;
	f1.setNumerator(4);
	f1.setDenominator(2);
	f1.getDouble();
	f1.outputReducedFraction();

	f2.setNumerator(20);
	f2.setDenominator(60);
	f2.getDouble();
	f2.outputReducedFraction();
	
	return 0;
}