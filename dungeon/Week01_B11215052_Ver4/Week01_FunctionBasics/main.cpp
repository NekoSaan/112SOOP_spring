/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/02/20
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/02/20
Description:
		Use clock to count time (And output) for following input tasks.
************************************************************************/
#include <iostream> // For cout and cin
#include <ctime> // For clock_t and clock()
using namespace std;

int main(void)
{
	clock_t startT, endT; // Variable to store the start of the gameloop
	startT = clock();
	endT = clock();
	clock_t globalStartT = startT;

	// Start the game loop
	/************************************************************************/
	int cnt = 0; // a counter to count the number of loops

	while (cnt != 15)
	{
		// once the time is passed 1 second, output the total time and reset the start time.
		if ((float)(endT - startT) / CLOCKS_PER_SEC > 1.0f)
		{
			startT = clock();
			cout << "Total time " << cnt << " at " << (float)endT / CLOCKS_PER_SEC << endl;
			cnt++;
		}
		endT = clock();
	}
	/************************************************************************/
}
