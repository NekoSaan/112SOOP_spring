/************************************************************************
File:
		Atoi.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/26
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/26
Description:
		Write a class that can convert a string into an integer.
************************************************************************/
#ifndef ATOI_H
#define ATOI_H
#include <string>
using namespace std;

//=======================================================================
//
// * Form Class
//=======================================================================
class Atoi {
	//=======================================================================
private:
	string beTrans;

public:
	// Default Constructor
	Atoi() { this->beTrans = ""; }
	Atoi(string s) { this->beTrans = s; }

	// Set string
	void SetString(string s) { this->beTrans = s; }

	// Get string
	const string GetString() { return this->beTrans; }

	// Get length
	int Length()
	{
		// pos/neg sign doesn't count in length of number
		int sign = (this->beTrans[0] == '-') ? 1 : 0;

		return this->beTrans.length() - sign;
	}

	// check is the given input digit or not
	bool IsDigital()
	{
		// check every char in beTrans is digit
		for (char& c : this->beTrans)
		{
			if (!isdigit(c) && c != '-') return false;
		}

		return true;
	}

	// convert string to integer
	int StringToInteger()
	{
		// convert std::string to const char*
		const char* str = this->beTrans.c_str();

		return atoi(str);
	}

};

#endif