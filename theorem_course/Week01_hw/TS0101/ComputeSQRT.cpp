/***********************************************************************
 * File:
		ComputeSQRT.cpp
 * Author:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
		2024/02/22
 * Editor:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
		2024/02/22
 * Description:
		Babylonian algorithm to compute the square root of a positive number.
***********************************************************************/
#include <iostream> // For input and output.
#include <iomanip> // For precise the float number.
#include <cmath> // For math calculate, absoulte function.

using namespace std;

int main(void)
{
	double n, prev, guess; // variables to store the result and temp.

	// reading the input from user until EOF.
	while (cin >> n && !cin.eof())
	{
		guess = n / 2.0f; // init guess was n / 2.

		// using do-while to approx the result, 
		// stop until the differ between the previous guess and the new guess less than 0.01f.
		do {
			double r = n / guess;
			prev = guess;
			guess = (guess + r) / 2.0f;
		} while (abs(guess - prev) > 0.01f);
		
		cout << setprecision(2) << fixed << guess << endl;
	}	return 0;
}
