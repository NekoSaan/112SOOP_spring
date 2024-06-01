/************************************************************************
File:
		PrintCombination.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/23
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/23
Description:
		Write a recursive function to enumerate all combinations of C(n,r).
************************************************************************/
#ifndef _COMB_H_
#define _COMB_H_
#include <iostream>
#include <vector>

using namespace std;

// Intent: Print all combination using BFS
// Pre: combination source
// Post: all possible result printed
// \param src : source of combination
// \param cur : current combination
// \param start : current start index (to prevent repeated combinations)
// \param choice : number of choices
void combRecursion(vector<int>& src, vector<int> cur, int start, int choice) {
	// if size of current combination fit number of choice, record it.
	if (cur.size() == choice) {
		for (int i = 0; i < choice; i++) {
			cout << cur[i];

			// Dealing with insane print specification.
			if (i != choice - 1) {
				cout << " ";
			}
		}

		cout << endl;
		return;
	}

	// using recursion (BFS) to find all possible result
	for (int i = start; i < src.size(); i++) {
		cur.push_back(src[i]); // push back next selected number
		combRecursion(src, cur, i + 1, choice);
		cur.pop_back(); // pop back to keep current combination same
	}
}

// Intent: Print all combination using BFS
// Pre: combination source
// Post: all possible result printed
// \param src : source of combination
// \param elem : amount of source elements
// \param choice : number of choices
void PrintCombination(int* src, int elem, int choice) {
	vector<int> tmp, source; // Declare two vector structure to use

	// transfer int* format into vector
	for (int i = 0; i < elem; i++) {
		source.push_back(src[i]);
	}

	// start recursion
	combRecursion(source, tmp, 0, choice);
}

#endif // _COMB_H_