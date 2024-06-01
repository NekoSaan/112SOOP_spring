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
		2024/03/20
Description:
		Check several Sudokus are valid or not.
************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// function to check sudoku is valid or not.
bool isValid(vector<vector<int>>& sudoku);

int main(void)
{
	while (1)
	{
		vector<vector<int>> sudoku; // 2-D array to store sudoku
		bool valid = true;

		// data input
		for (int i = 0; i < 9; i++)
		{
			vector<int> row; // array to store each row.

			for (int j = 0; j < 9; j++)
			{
				int num; // variables to store number

				// read until EOF
				if (!(cin >> num)) return 0;

				// if the number is out of range, set the flag to false
				if (num < 1 || num > 9) valid = false;

				cin.ignore(1, ','); // skip the comma.

				row.push_back(num);
			}

			sudoku.push_back(row);
		}

		if (valid && isValid(sudoku)) cout << "True\n";
		else cout << "False\n";
	}
}


bool isValid(vector<vector<int>>& sudoku)
{
	// Checking horizontal
	for (auto& row : sudoku)
	{
		int freq[10] = { 0 }; // array to record the number appear times

		// record the frequency that each number appear
		for (int i = 0; i < 9; i++)
		{
			freq[row[i]]++;
		}

		// Checking that all the number 1 ~ 9 appear only once.
		for (int i = 1; i < 10; i++)
		{
			if (freq[i] != 1) return false;
		}
	}

	// Checking vertical
	for (int col = 0; col < 9; col++)
	{
		int freq[10] = { 0 }; // array to record the number appear times

		// record the frequency that each number appear
		for (int row = 0; row < 9; row++)
		{
			freq[sudoku[row][col]]++;
		}

		// Checking that all the number 1 ~ 9 appear only once.
		for (int i = 1; i < 10; i++)
		{
			if (freq[i] != 1) return false;
		}
	}

	// Checking Square area
	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			int freq[10] = { 0 }; // array to record the number appear times

			// record the frequency that each number appear
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					freq[sudoku[i + k][j + l]]++;
				}
			}

			// Checking that all the number 1 ~ 9 appear only once.
			for (int i = 1; i < 10; i++)
			{
				if (freq[i] != 1) return false;
			}
		}
	}

	return true;
}

/*
1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7

8,2,7,1,5,4,3,9,6
9,6,5,3,2,7,1,4,8
3,4,1,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7

8,2,7,1,5,4,3,9,0
9,6,5,3,2,7,1,4,8
3,4,1,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7

1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,0,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,7,5,6,1

*/