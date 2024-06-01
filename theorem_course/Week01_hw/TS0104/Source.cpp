/***********************************************************************
 * File: 
		Source.cpp
 * Author: 
		Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date: 
		2024/02/22
 * Editor: 
		Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date: 
		2024/02/22
 * Description: 
		Given an arbitrary integer INPUT ( INPUT ), 
		follow the requirements to output it.
***********************************************************************/
#include <iostream> // For input and outputs
#include <string> // For string format and relative fucntions.
#include <iomanip>

using namespace std;

int main(void)
{
	string num; // a variable to store data, reusable.

	// reading input from user until EOF.
	while (cin >> num)
	{
		// if the number length is greater than 9, no need to meets digits, directly output it.
		if (num.size() > 9)
		{
			cout << num << endl;
		}
		else 
		{
			cout << setw(10) << num << endl;
		}
	}
	return 0;
}