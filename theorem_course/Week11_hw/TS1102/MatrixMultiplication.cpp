/************************************************************************
File:
		MatrixMultiplication.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		compute Matrix Multiplication program
************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int row1, col1, row2, col2; // variables to store row & col of matrices
	cin >> row1 >> col1 >> row2 >> col2; // input size of matrices

	// if col1 != row2, multiplication fail
	if (col1 != row2) {
		cout << "Matrix multiplication failed.";
		return 0;
	}

	// Declare two matrices
	vector<vector<int>> m1(row1, vector<int>(col1));
	vector<vector<int>> m2(row2, vector<int>(col2));

	// insert matrix one
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			cin >> m1[i][j];
		}
	}

	// insert matrix two
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			cin >> m2[i][j];
		}
	}

	// result matrix
	vector<vector<int>> res(row1, vector<int>(col2));

	// multiplication start, iterate through matrices
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			for (int idx = 0; idx < row2; idx++) {
				res[i][j] += m1[i][idx] * m2[idx][j];
			}
		}
	}

	// print multiplication result
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			cout << res[i][j];

			// Dealing with insane print specification
			if (j + 1 != col2) {
				cout << " ";
			}
		}

		cout << endl;
	}
}