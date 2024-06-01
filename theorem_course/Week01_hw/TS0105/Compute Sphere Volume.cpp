/***********************************************************************
 * File:
		Compute Sphere Volume.cpp
 * Author:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
		2024/02/22
 * Editor:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
		2024/02/22
 * Description:
		Given a radius r, compute and output the volume of a sphere with radius r.
***********************************************************************/
#define PI 3.14159265358979323846

#include <iostream> // For input and output
#include <cmath> // For math calculate
#include <iomanip> // For precise the float number

using namespace std;

int main(void)
{
	double r; // a variable to store number, reusable.

	// reading input until EOF.
	while (cin >> r && !cin.eof())
	{
		// sphere's volume formula.
		double v = pow(r, 3) / 3.0 * 4.0 * PI;

		// output the result.
		cout << fixed << setprecision(6) << v << endl;
	}

	return 0;
}