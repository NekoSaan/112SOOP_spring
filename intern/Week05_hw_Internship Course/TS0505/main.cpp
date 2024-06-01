/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/19
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/19
Description:
		Write a program that records at most 10 student data by structures.
************************************************************************/
#include<iostream>
#include"Point.h"
using namespace std;

int main(void) {
	Point point;

	point.Set(0, 5);
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;

	point.Reflect();
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;

	point.Move(1, 2);
	cout << point. GetHorizontal() << " " << point. GetVertical() << endl;

	point.Rotate();
	cout << point.GetHorizontal() << " " << point.GetVertical() << endl;

	Point copy = point;
	cout << "Copy point:" << endl;
	cout << copy.GetHorizontal() << " " << copy.GetVertical() << endl;
}
