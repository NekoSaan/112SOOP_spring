/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/12
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/12
Description:
		Implement a class named Point to store and manipulate the position
		of the point on the screen.
************************************************************************/
#include <iostream> // For input & output
#include "Point.h"

using namespace std;

int main(void) {
	Point point;

	point.Set(0, 5);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	point.Move(1, 2);
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

	for (int i = 0; i < 4; i++)
	{
		point.Rotate();
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
	}

	return 0;
}