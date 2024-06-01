/************************************************************************
File:
		PrimeNumber.cpp
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
#include "PrimeNumber.h"

// Get prime number value
int PrimeNumber::get(void) {
	return value;
}

// Intent: check number is a prime number or not
// Pre: A prime number
// Post: return true or false accroding to parameter
// \param n : variable to store the number that want to verify
bool isPrime(int n) {
	if (n == 2 || n == 1) {
		return true;
	}

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

// Intent: find next prime number
// Pre: A prime number
// Post: return prime number greater than last one
// \param n : variable to store prime number
int nextPrime(int n) {
	while (true) {
		n++;

		if (isPrime(n)) {
			return n;
		}
	}

	return 0;
}

// Intent: find last prime number
// Pre: A prime number
// Post: return prime number less than paramter
// \param n : variable to store prime number
int lastPrime(int n) {
	while (true) {
		n--;
		if (isPrime(n)) {
			return n;
		}
	}

	return 0;
}

// prefix ++
PrimeNumber& PrimeNumber::operator++() {
	value = nextPrime(value);

	return *this;
}

// postfix ++;
PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber p(value);
	value = nextPrime(value);

	return p;
}

// prefix --
PrimeNumber& PrimeNumber::operator--() {
	value = lastPrime(value);

	return *this;
}

// postfix --
PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber p(value);
	value = lastPrime(value);

	return p;
}