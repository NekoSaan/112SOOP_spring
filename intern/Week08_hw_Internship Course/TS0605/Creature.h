/************************************************************************
File:
		Creature.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/11
Description:
		You are making observations on several unknown creatures and you
		need to record the number of various body parts of them
		(e.g. How many legs, tails...) and generate diary observation logs.

		You feel that manual diary logging is too cumbersome and want to
		design a program to automatically generate logs. You plan to design
		two classes Diary and Creature to handle this.
************************************************************************/
#ifndef _CREATURE_H_
#define _CREATURE_H_
#include "Diary.h"
#include <algorithm>

// body type structure
typedef struct Body_Parts {
	string name;
	int amount = 0;
} body_parts;

// Creature Class
class Creature {
private:
	int index = 0;
	string name;
	int start_day_index;
	vector<body_parts> body;

public:
	// Default Constructor
	Creature() { name = ""; }

	// Contains a creature named name.
	Creature(string);
	
	// Copy Constructor
	Creature(string, Creature);

	// Operators overloading
	Creature& operator[](string);

	// Assignment
	Creature& operator=(int);

	// Addition
	Creature& operator+=(int);
	int operator+(int);

	// Substraction
	Creature& operator-=(int);
	int operator-(int);

	// Actions
	void PrintStatus(void);
	void PrintLog(void);
};

#endif // _CREATURE_H_