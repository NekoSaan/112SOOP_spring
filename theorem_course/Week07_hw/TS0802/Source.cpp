/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/03
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/03
Description:
		Matrices multiplication
************************************************************************/
#include <iostream> // for cin & cout
#include <vector> // for vector structure

using namespace std;

int main(void) {
	int rowA, colA, rowB, colB; // variables to store the A, B 's size

	cin >> rowA >> colA >> rowB >> colB; // size of matrix A, B

	vector<vector<int>> A, B; // matrix A, B

	// setup matrix A
	for (int i = 0; i < rowA; i++) {
		vector<int> row;

		for (int j = 0; j < colA; j++) {
			int tmp;
			cin >> tmp;

			row.push_back(tmp);
		}

		A.push_back(row);
	}

	// setup matrix B
	for (int i = 0; i < rowB; i++) {
		vector<int> row;

		for (int j = 0; j < colB; j++) {
			int tmp;
			cin >> tmp;

			row.push_back(tmp);
		}

		B.push_back(row);
	}

	if (colA != rowB) {
		cout << "Matrix multiplication failed.";
		return 0;
	}

	// matrix multiplication
	vector<vector<int>> res(rowA, vector<int>(colB, 0));

	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colA; j++) {
			for (int k = 0; k < colB; k++) {
				res[i][k] += A[i][j] * B[j][k];
			}
		}
	}

	// print the result
	for (int i = 0; i < rowA; i++) {
		for (int j = 0; j < colB; j++) {
			cout << res[i][j];

			if (j != colB - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}