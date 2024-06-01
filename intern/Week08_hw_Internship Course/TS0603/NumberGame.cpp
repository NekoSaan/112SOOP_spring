/************************************************************************
File:
		NumberGame.cpp
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
#include "NumberGame.h"

// set the given integer A.
void NumberGame::SetInput(unsigned int input) {
	A = input;
}

// splitting the integer A into several digits.
void NumberGame::ProcessInput(void) {
	unsigned int tmp = A;

	// split each digits
	while (tmp) {
		if (tmp % 10 != 0) {
			digits.push_back(tmp % 10);
		}

		tmp /= 10;
	}

	sort(digits.begin(), digits.end());
}

// set the file name of the file where list S is located.
void NumberGame::SetFileName(string fileName) {
	this->fileName = fileName;
}

// read list S from the file.
void NumberGame::LoadNumberList(void) {
	ifstream f(fileName, ios::in);

	unsigned int curNum;

	// validiate the list
	while (f >> curNum) {
		if (curNum == 1 && find(digits.begin(), digits.end(), 1) == digits.end()) {
			continue;
		}

		unsigned int tmp;

		// algorithm to validiate legit number
		for (int i = digits.size() - 1; i >= 0; i--) {
			tmp = curNum;
			
			for (int j = i; j >= 0; j--) {
				if (tmp % digits[j] == 0) {
					tmp /= digits[j];
				}

				if (tmp == 1) {
					break;
				}
			}

			if (tmp == 1) {
				break;
			}
		}

		if (tmp == 1) {
			valid.push_back(curNum);
		}
	}

	f.close();
}

// print all the valid numbers in S ascendingly
void NumberGame::PrintAllValid(void) {
	// print out ascendingly
	sort(valid.begin(), valid.end());

	for (unsigned int& n : valid) {
		cout << n << endl;
	}
}

// reset all variables.
void NumberGame::Reset(void) {
	A = 0;
	digits.clear();
	valid.clear();
	fileName = "";
}