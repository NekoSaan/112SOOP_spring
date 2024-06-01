#include "Fraction.h"

// Set numerator
void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

// Set denominator
void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

// Get double or int format of the fraction, output it.
void Fraction::getDouble()
{
	// if the nu divisible by de, output the integer format
	// otherwise, output the double format
	if (this->numerator % this->denominator == 0) 
	{
		cout << this->numerator / this->denominator << endl;
	}
	else 
	{
		cout << fixed << setprecision(6) << (double)this->numerator / (double)this->denominator << endl;
	}
}

// process the fraction, then output the result.
void Fraction::outputReducedFraction()
{
	// if the nu divisible by de, output the integer format.
	// otherwise, find the greatest common divisor of nu and de.
	// then output the Reduced Fraction.
	if (this->numerator % this->denominator == 0)
	{
		cout << this->numerator / this->denominator << endl;
	}
	else 
	{
		int gcd = GCD(this->numerator, this->denominator);

		cout << this->numerator / gcd << "/" << this->denominator / gcd << endl;
	}
}

// find greatest common divisor by recursive
int Fraction::GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}