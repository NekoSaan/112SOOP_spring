/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/05/14
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/05/14
Description:
		Please write a template-based function that calculates and returns
		the absolute value of the difference between two numeric values
		passed with Template.h

		Note that the function should operate with any numeric data type
		(e.g. float, int, double, char).
************************************************************************/
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

// Intent: Calculate the absolute value of the difference between two numeric values
// Pre: value1 and value2 are numeric data type
// Post: return the absolute value of the difference between two numeric values
// \param value1: the first numeric value
// \param value2: the second numeric value
template<typename T>
double absoluteValue(const T& value1, const T& value2) {
	return (value1 > value2) ? value1 - value2 : value2 - value1;
}

// overload not working

#endif // _TEMPLATE_H_