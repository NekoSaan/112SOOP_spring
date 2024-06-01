/***********************************************************************
 * File:
		Source.cpp
 * Author:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
		2024/02/28
 * Editor:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
		2024/02/28
 * Description:
		Computes the average and standard deviation.
***********************************************************************/
#include <iostream> // For input & output.
#include <cmath> // For math compute.
#include <vector> // vector relative functions

using namespace std;

int main(void)
{
	long long int n; // Variable to store n, reusable.

	while (cin >> n && !cin.eof())
	{
		double m = 0.0, d = 0.0; // Variabless to store average value and standard deviation.
		vector<double> s; // a vector to store each input s_i.

		// Input s_i and calculate the average value and standard deviation.
		for (size_t i = 0; i < n; i++)
		{
			double tmp;
			cin >> tmp;

			s.push_back(tmp);
			m += s[i];
		}

		m /= n;

		// Calculate the standard deviation.
		for (size_t i = 0; i < n; i++)
		{
			d += pow((s[i] - m), 2);
		}

		d /= n;

		cout << "Average:" << m << "\t" << "Standard deviation:" << sqrt(d) << endl;
	}
}