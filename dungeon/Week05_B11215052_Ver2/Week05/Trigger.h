#pragma once
#include <iostream>
#include "Position.h"
#include "Hero.h"

//************************************************************
// Trigger Class
//************************************************************
class Trigger {
private:
	Position tPos;
	char tIcon;
	int expAmount;
	
public:
	// Default Constructor
	Trigger(int x, int y, int expAmount)
	{
		this->tPos.x = x;
		this->tPos.y = y;
		this->tIcon = 'T';
		this->expAmount = expAmount;
	}

	// Get trigger's position.
	Position getPos(void) { return this->tPos; }
	
	// Get Icon of trigger.
	char getIcon(void) { return this->tIcon; }

	// Get exp per step on trigger.
	int getExpAmount(void) { return this->expAmount; }

	// Check if hero step on the trigger or not.
	void update(Hero& hero)
	{
		Position hPos = hero.getPos();

		// if it was, gain exp.
		if (hPos.x == this->tPos.x && hPos.y == this->tPos.y)
		{
			hero.gainEXP(this->expAmount);
		}
	}
};

