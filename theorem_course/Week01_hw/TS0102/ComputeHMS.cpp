/***********************************************************************
 * File:
		ComputeHMS.cpp
 * Author:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
		2024/02/22
 * Editor:
		Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
		2024/02/22
 * Description:
		Given a integer A as a time in seconds. 
		Convert the format of A from (seconds) to (hours: minutes: seconds).
***********************************************************************/
#define ll long long // shor the syntax of long long format.

#include <iostream> // For input and output.
using namespace std;

int main(void)
{
	unsigned ll int h, m, n; // Variables to store hours, minutes and seconds.

	while (cin >> n)
	{
		// 3600 secs per hour
		h = n / 3600;
		n %= 3600;

		// 60 secs per minute
		m = n / 60;
		n %= 60;

		cout << h << " hours " << m << " minutes and " << n << " seconds" << endl;
	}
	return 0;
}