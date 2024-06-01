#pragma once
#include "Position.h"
#include "main.h"

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero
{
private:
	Position sPos;	  // Hero location
	char sIcon = 'H'; // Hero icon
	int hp;			  // Hero hp
	int sLevel = 1;	  // Level
	int sMaxExp;	  // Level update experience
	int sCurrentExp;  // current exp hero has
	int power;
	int cooldown;

public:
	// Default constructor
	Hero()
	{
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sLevel = 1;
		this->sCurrentExp = 0;
		this->sMaxExp = 15;
		this->sIcon = 'H';
		this->hp = 100;
		this->power = 5;
		this->cooldown = 0;
	};

	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100, int power = 5, int cooldown = 0)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
		this->power = power;
		this->cooldown = cooldown;
	};

	// Setting constructor
	Hero(Position &pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100, int power = 5, int cooldown = 0)
	{
		this->sPos = pos;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
		this->power = power;
		this->cooldown = cooldown;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y)
	{
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char &icon) { this->sIcon = icon; }

	// Set level
	void setLevel(int level) { this->sLevel = level; }

	// Set exp
	void setExp(int exp) { this->sCurrentExp = exp; }

	// Set MaxExp
	void SetMaxExp(int maxexp) { this->sMaxExp = maxexp; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Get level
	int getLevel(void) { return this->sLevel; }

	// Get Exp
	int getExp(void) { return this->sCurrentExp; }

	// Get Max
	int getMaxExp(void) { return this->sMaxExp; }

	// Get Hp
	int getHP(void) const { return this->hp; }

	// Get power of hero
	int getPower(void) const { return this->power; }

	// Get attack cooldown
	int getAttackCooldown(void)
	{
		return this->cooldown;
	}

	// reduce the cooldown by 1
	void reduceAttackCooldown(void)
	{
		if (this->cooldown) this->cooldown -= 1;
	}

	// Incrementally move the elements
	void move(int x, int y)
	{
		// Compute the next position
		Position next;
		next.x = this->sPos.x + x;
		next.y = this->sPos.y + y;

		if (isPositionValid(next))
		{
			this->sPos = next;
		}
		else
		{
			std::cout << "Invalid location\n";
		}
	}

	// Calculate gain of EXP
	void gainEXP(int points)
	{
		this->sCurrentExp += points;

		// If hero level up, update the hero's state.
		if (this->sCurrentExp >= this->sMaxExp)
		{
			this->sCurrentExp -= this->sMaxExp;
			this->sMaxExp += 10;
			this->hp = 100;
			this->sLevel++;
		}
	}

	// Hero hurt by Creature.
	void damage(int points)
	{
		this->hp -= points;
	}

	// Hero's Attack
	bool attack(Position cPos)
	{
		// check is the attack ready or not?
		if (this->cooldown) return false;

		this->cooldown = 2;
		std::cout << "Hero attacked!\t";

		// check is the creature in the attacking range.
		if (abs(this->sPos.x - cPos.x) <= 1 && abs(this->sPos.y - cPos.y) <= 1)
		{
			std::cout << "Hit creature." << std::endl;
			return true;
		}

		// if not, attack missed.
		std::cout << "Missed." << std::endl;
		return false;
	}
};
