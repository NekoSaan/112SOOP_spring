/************************************************************************
File:
		PrimeNumber.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/10
Description:
		Define a class named PrimeNumber that stores a prime number.
************************************************************************/
#ifndef _PRIME_H_
#define _PRIME_H_

class PrimeNumber {
public:
	int value;

	// Get current value of PrimeNumber
	int get(void);

	// Constructor
	PrimeNumber() : value(1) {};
	PrimeNumber(int _value) : value(_value) {};

	// prefix ++
	PrimeNumber& operator++();

	// postfix ++;
	PrimeNumber operator++(int);

	// prefix --
	PrimeNumber& operator--();

	// postfix --
	PrimeNumber operator--(int);

};
#endif // _PRIME_H