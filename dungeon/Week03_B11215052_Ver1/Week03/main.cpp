/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/02/28
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/02/28
Description:
		Draw and print out the canvas.
************************************************************************/
#include <iostream> // For print out information.
#include <stdio.h> // For print out information.

using namespace std;

void drawBoard(); //Function to draw board.
void makeBoard(); //Function to make board.
void modifyBoard();	//Function to modify board.

const int DUNGEN_ROW = 10, DUNGEN_COL = 20;
char dungenMap[DUNGEN_ROW][DUNGEN_COL];

int main(void)
{
	makeBoard();
	drawBoard();
	modifyBoard();
	drawBoard();
}

void drawBoard()
//==================================================================
{
	// Draw out the whole board.
	/************************************************************************/
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
			cout << dungenMap[i][j];
		}
		cout << endl;
	}
	/************************************************************************/
}

void makeBoard()
//==================================================================
{
	// Enter symbol for wall and blank then create array.
	/************************************************************************/
	char wall, blank; // Variables to store the symbol for wall and blank.

	cout << "Enter symbol for wall: ";
	cin >> wall;

	cout << "Enter symbol for blank: ";
	cin >> blank;

	// Create the dungeon map.
	for (int i = 0; i < DUNGEN_ROW; i++)
	{
		for (int j = 0; j < DUNGEN_COL; j++)
		{
			// If the position is at the edge, set it to wall, otherwise set it to blank.
			if (i == 0 || i == DUNGEN_ROW - 1 || j == 0 || j == DUNGEN_COL - 1)
			{
				dungenMap[i][j] = wall;
			}
			else
			{
				dungenMap[i][j] = blank;
			}
		}
	}
	/************************************************************************/
}

void modifyBoard()
//==================================================================
{
	// Function for modifying board given position and char to change.
	/************************************************************************/
	char symbol; // Variable to store the symbol for modifying position.
	int posX, posY; // Variables to store the position of modifying position.

	cout << "\nEnter symbol for modifying position: ";
	cin >> symbol;

	cout << "Enter X of modifying position: ";
	cin >> posX;

	cout << "Enter Y of modifying position: ";
	cin >> posY;

	// check if the modifying position is valid or not. if not, print out error message.
	// otherwise, modify the position.
	if (posX < 0 || posX >= DUNGEN_ROW || posY < 0 || posY >= DUNGEN_COL)
	{
		cout << "Invalid input" << endl;
	}
	else
	{
		dungenMap[posX][posY] = symbol;
	}
	/************************************************************************/
}