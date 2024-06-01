/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/02/20
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/02/21
Description:
		Output W,A,S,D after input, ESC to stop process.
************************************************************************/
#include <iostream> // For print out information
#include <conio.h>	// For getch() function
using namespace std;

// Define inputs and its index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

// Detect state of input
void keyUpdate(bool key[]);

int main(void)
{
	// Initialize state of key
	bool gKeyState[ValidInput::INVALID];

	// Obtain and update the input using a loop
	/************************************************************************/
	while (true)
	{
		// continuously call the keyUpdate function to detect the input state.
		keyUpdate(gKeyState);

		// If the ESC key is pressed, end the program.
		if (gKeyState[ValidInput::EESC])
		{
			break;
		}
	}
	/************************************************************************/
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	// init the key state
	for (int i = 0; i < ValidInput::INVALID; i++)
	{
		key[i] = false;
	}
	
	char input = _getch(); // waiting an chracter input from user.

	/************************************************************************/
	// Implement a switch for output calls
	switch (input)
	{
		case 'w':
		case 'W':
			cout << "Key W is pressed." << endl;
			key[ValidInput::EW] = true;
			break;
		case 's':
		case 'S':
			cout << "Key S is pressed." << endl;
			key[ValidInput::ES] = true;
			break;
		case 'a':
		case 'A':
			cout << "Key A is pressed." << endl;
			key[ValidInput::EA] = true;
			break;
		case 'd':
		case 'D':
			cout << "Key D is pressed." << endl;
			key[ValidInput::ED] = true;
			break;
		case 32:
			key[ValidInput::ESPACE] = true;
			break;
		case 27:
			cout << "Key ESC is pressed. End program." << endl;
			key[ValidInput::EESC] = true;
			break;
		default:
			key[ValidInput::INVALID] = true;
	}
	/************************************************************************/
}
