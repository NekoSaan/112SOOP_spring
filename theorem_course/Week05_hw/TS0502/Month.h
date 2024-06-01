#ifndef MONTH_H
#define MONTH_H
#pragma once
#include <iostream>
using namespace std;

//******************************************************************
//
// * Month Class
//==================================================================
class Month {
private:
	int month;
public:
	// Constructor
	Month();
	Month(char first, char second, char third);
	Month(int monthInt);

	// Destructor
	~Month();

	// Actions
	void inputInt();
	void inputStr();
	void outputInt();
	void outputStr();
	Month nextMonth();
};

#endif