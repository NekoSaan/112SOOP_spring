/************************************************************************
File:
		NumberGame.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/10
Description:
		Design a class called NumberGame to implement a game.
************************************************************************/
#ifndef _NUMBER_GAME_
#define _NUMBER_GAME_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class NumberGame {
public:
	unsigned int A = 0;
	vector<unsigned int> digits, valid;
	string fileName;

	// Default Constructor
	NumberGame() {};

	// set the given integer A.
	void SetInput(unsigned int);

	// splitting the integer A into several digits.
	void ProcessInput(void);

	// set the file name of the file where list S is located.
	void SetFileName(string);

	// read list S from the file.
	void LoadNumberList(void);

	// print all the valid numbers in S ascendingly
	void PrintAllValid(void);

	// reset all variables.
	void Reset(void);
};

#endif // _NUMBER_GAME_