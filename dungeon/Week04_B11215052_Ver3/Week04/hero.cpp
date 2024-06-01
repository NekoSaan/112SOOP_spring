#include "main.h"
#include "hero.h"

// Set position
void Hero::setPos(Position pos) { this->sPos = pos; }
void Hero::setPos(int x, int y)
{
	this->sPos.x = x;
	this->sPos.y = y;
}

// Set icon
void Hero::setIcon(char& icon) { this->sIcon = icon; }

// Get position
Position Hero::getPos(void) { return this->sPos; }

// Get Icon
char Hero::getIcon(void) { return this->sIcon; }

// Incrementally move the elements
void Hero::move(int deltaX, int deltaY)
{
	Position newPos = { this->sPos.x + deltaX, this->sPos.y + deltaY };

	// Check if the new position is valid or not?
	if (isPositionValid(newPos))
	{
		setPos(newPos);
	}
}