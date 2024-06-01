/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/02/21
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/02/21
Description:
		Output character position after W, A, S, D input.
		Output invalid if destination out of boundary.
		ESC to stop process.
************************************************************************/
#include <iostream> // For print out information
#include <conio.h>	// For getch() function

using namespace std;

bool tryMove(int deltaX, int deltaY);
bool checkValidDst(int x, int y);

int posX = 0, posY = 0;	   // global param to keep the character position
const int DUNGEN_SIZE = 5; // For each dimension, -DUNGEN_SIZE < pos < DUNGEN_SIZE

int main(void)
{
	// Obtain and update the input using a loop
	while (true)
	{
		char input = _getch(); // reading a input chracter from user.

        /************************************************************************/
		bool moved = false; // flag to check the movement is successful or not?

		// using a switch to check the input.
		switch (input)
		{
		case 'w':
			moved = tryMove(posX, posY + 1);
			break;
		case 'a':
			moved = tryMove(posX - 1, posY);
			break;
		case 's':
			moved = tryMove(posX, posY - 1);
			break;
		case 'd':
			moved = tryMove(posX + 1, posY);
			break;
        case 27: // ESC pressed, end game.
            exit(0);
			break;
		}

		// if the move is failed, print out the message.
		if (!moved)
		{
			cout << "Failed to move" << endl;
		}

        cout << "Character position: (" << posX << "," << posY << ")" << endl;
		/************************************************************************/
	}
}

//******************************************************************
//
// * Move character with input delta, return true if successful otherwise false
//==================================================================
bool tryMove(int deltaX, int deltaY)
{
	/************************************************************************/
	// check if the destination is valid or not.
	if (checkValidDst(deltaX, deltaY))
	{
		// if valid, renew the position and print it out.
		posX = deltaX;
		posY = deltaY;
		
		return true;
	}
	return false;
	/************************************************************************/
}
//******************************************************************
//
// * Check if given position is a valid destination, return true if valid otherwise false
//==================================================================
bool checkValidDst(int x, int y)
{
	/************************************************************************/
	// check if the destination is out of boundary or not.
	if (x <= -DUNGEN_SIZE || x >= DUNGEN_SIZE || y <= -DUNGEN_SIZE || y >= DUNGEN_SIZE)
	{
		return false;
	}
	return true;
	/************************************************************************/
}
