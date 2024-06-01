/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/23
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/23
Description:
		Word game is a popular puzzle game that involves finding words
		from a grid of randomly generated letters. Words must be at least
		three letters long and formed from neighboring letters. Letters
		are not allowed to be used more than once in one word, and it is
		valid to move diagonally.
************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 8 directions
vector<pair<int, int>> dir = {
	{-1, -1}, {0, -1}, {1, -1}, // left-up, up, right-up
	{-1, 0}, {1, 0},			// left, right
	{-1, 1}, {0, 1}, {1, 1}		// left-down, down, right-down
};

// valid words list
vector<string> wordList;

// printed records
vector<string> rec;

// wordsGame solver, using DFS
bool wordsGame(vector<vector<char>>& src, vector<vector<bool>> used, string cur, string target, int nextIndex, int x, int y);

int main(void) {
	ifstream f("words.txt", ios::in); // open "words.txt" file
	string tmp;

	// reading words list
	while (f >> tmp) {
		wordList.push_back(tmp);
	}

	f.close();

	vector<vector<char>> grid; // 2-dim array to store alphabet grid

	// input alphabet grid, each testcase has 4 line
	for (int i = 0; i < 4; i++) {
		getline(cin, tmp);
		vector<char> row; // vector variable to store each line data

		// each line has 4 alphabet
		for (int j = 0; j < 4; j++) {
			row.push_back(tmp[j]);
		}

		grid.push_back(row);
	}

	// initialize used grid
	vector<vector<bool>> used(4, vector<bool>(4, true));

	// start using recursion to find all valid result
	// iterate through whole list
	for (string& word : wordList) {
		// iterate through alphabet table
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				// find same first word to decide the start point
				if (grid[i][j] == word[0]) {
					if (find(rec.begin(), rec.end(), word) == rec.end() && wordsGame(grid, used, "", word, 1, j, i)) {
						break;
					}
				}
			}
		}
	}
}

// Intent: find all possible words using recursion (DFS)
// Pre: alphabet grid & valid word list
// Post: all possible result printed
// \param src : source alphabet grid
// \param used : tracking traveled path
// \param cur : current combine word
// \param target : combine target
// \param nextIndex : next index of target string
// \param x : current x component
// \param y : current y component
bool wordsGame(vector<vector<char>>& src, vector<vector<bool>> used, string cur, string target, int nextIndex, int x, int y) {
	used[y][x] = false; // set current position to "used"
	cur.push_back(src[y][x]); // add current alphabet to creaing word

	// if the creating word fitted to target and isn't repeat, print & record the result then return true.
	if (cur == target && find(rec.begin(), rec.end(), cur) == rec.end()) {
		cout << cur << endl;
		rec.push_back(cur);
		return true;
	}

	bool res = false; // Is there a solution? flag

	// travel through 8 directions
	for (int i = 0; i < 8; i++) {
		int newX = x + dir[i].first;
		int newY = y + dir[i].second;

		if (newX >= 0 && newY >= 0 && newX < 4 && newY < 4 && used[newY][newX] && src[newY][newX] == target[nextIndex]) {
			res |= wordsGame(src, used, cur, target, nextIndex + 1, newX, newY);
		}
	}

	return res;
}