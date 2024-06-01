#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <math.h>	 // pow() and sqrt()
#include <ctime>	 // for time loop function
#include <conio.h>	 // _getch() <= to read input without enter "ENTER" key
#include <algorithm> // for max and min function
#include <vector>	 // For array

//************************************************************
// The location in the board
//************************************************************
struct Position
{
	int x; // x, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

// clip algroithm
float clip(float n, float minimun, float maximum);

#endif