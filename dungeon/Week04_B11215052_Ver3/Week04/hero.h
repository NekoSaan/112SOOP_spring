#ifndef HERO_H
#define HERO_H
#include "main.h"

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position sPos;	// Hero location
	char sIcon; // Hero icon

public:
	// Default constructor
	Hero()
	{
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'H';
	};

	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);	
	void setIcon(char& icon); // Set icon
	Position getPos(void); // Get position
	char getIcon(void); // Get Icon
	void move(int deltaX, int deltaY); // Incrementally move the elements
};

#endif