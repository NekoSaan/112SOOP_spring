/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/26
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/27
Description:
		Shisensho is a classic tile-matching game.
		The objective of the game is to match all the pairs and clear the
		board.
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format
#include <vector> // for vector structure

using namespace std;

// Position structure
struct Position
{
	int x;
	int y;
};

// play board, expand 2 rows & 2 cols for path
int playBoard[8][8] = { 0 };

// set up the play board
void setUp(void);

// find path to target
bool havePath(Position cur, Position& target, int dir, int turns);

// 4 directions
vector<pair<int,int>> direct = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int main(void)
{
	setUp(); // setup the board

	Position p1, p2; // variables to store pair's position
	
	while (cin >> p1.x)
	{
		// input matches and pre-process
		cin >> p1.y >> p2.x >> p2.y;
		p1.x += 1, p1.y += 1, p2.x += 1, p2.y += 1;

		// check is the selected matches are already eliminated or not?
		// check is the matches same or not?
		if (playBoard[p1.y][p1.x] == 0 || playBoard[p2.y][p2.x] == 0 || playBoard[p1.y][p1.x] != playBoard[p2.y][p2.x])
		{
			cout << "bad pair" << endl;
			continue;
		}

		// check is the matches valid or not?
		bool flag = false;

		for (int i = 0; i < 4; i++)
		{
			flag = flag || havePath({ p1.x + direct[i].first, p1.y + direct[i].second }, p2, i, 0);
		}

		// check is the two matches have a path to connect together
		if (flag)
		{
			cout << "pair matched" << endl;
			playBoard[p1.y][p1.x] = 0;
			playBoard[p2.y][p2.x] = 0;
		}
		else {
			cout << "bad pair" << endl;
		}

		// printBoard();
	}
}

//=======================================================================
//
// * set up the play board by user's input
//=======================================================================
void setUp(void)
//=======================================================================
{
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			cin >> playBoard[i][j];
		}
	}
}

//=======================================================================
//
// * 深度優先搜尋，但只有前、左、右三個方向。同時紀錄方向，判斷是否有轉彎
//=======================================================================
bool havePath(Position cur, Position& target, int dir, int turns)
{
	// check is the count of turn less than 2 or not?
	if (turns > 2) return false;

	// check is the target found or not?
	if (cur.x == target.x && cur.y == target.y) return true;

	// check is the current position out of range or not?
	if (cur.x < 0 || cur.x > 7 || cur.y < 0 || cur.y > 7) return false;

	// check is the current position empty or not?
	if (playBoard[cur.y][cur.x] != 0) return false;

	return havePath({ cur.x + direct[dir].first, cur.y + direct[dir].second }, target, dir, turns) ||
		havePath({ cur.x + direct[(dir + 3) % 4].first, cur.y + direct[(dir + 3) % 4].second }, target, (dir + 3) % 4, turns + 1) ||
		havePath({ cur.x + direct[(dir + 1) % 4].first, cur.y + direct[(dir + 1) % 4].second }, target, (dir + 1) % 4, turns + 1);
}