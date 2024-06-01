#pragma once
#include <string>
#include "Position.h"
#include "main.h"
//************************************************************
// Hero Class, only has requirement part for example
//************************************************************

class Hero {

private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon
	int			hp;
	int			sLevel = 1;     // Level
	int			sMaxExp;		// Level update experience
	int			sCurrentExp;	// current exp hero has

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sLevel = 1;
		this->sCurrentExp = 0;
		this->sMaxExp = 15;
		this->sIcon = 'H';
		this->hp = 100;
	};
	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos = pos;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

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

	int getHP() const { return this->hp; }

	// Incrementally move the elements 
	void move(Position delta) {
		// Compute the next position
		Position next = this->sPos + delta;

		// checking operator overloading working
		sPos = *this + delta;
		*this += delta;
		sPos = *this - delta;
		*this -= delta;
		sPos = *this * 1;

		if (isPositionValid(next))
			this->sPos = next;
		else {
			std::cout << "Invalid location\n";
		}
	}

	// Calculate Gain of EXP
	void gainEXP(int points) {
		int number = points;
		while (number > 0) {
			if (sCurrentExp + number >= sMaxExp) {//level up
				number -= (sMaxExp - sCurrentExp);
				sCurrentExp = 0;
				sMaxExp = (int)((float)sMaxExp * 1.2f);
				sLevel++;
			}
			else {
				sCurrentExp += number;
				number = 0;
			}
		}
	}
	void damage(int points) {
		hp = hp - points;
		if (hp < 0)
			hp = 0;
	}

	// Operator overloading
	// Adding up two positions
	Position operator+(const Position& pos) {
		return sPos + pos;
	}

	// Adding up two positions, then assign to l-value
	Hero& operator+=(const Position& pos) {
		sPos += pos;
		return *this;
	}

	// Substracting two positions
	 Position operator-(const Position& pos) {
		 return sPos - pos;
	}

	// Substracting two positions, then assign to l-value
	 Hero& operator-=(const Position& pos) {
		sPos -= pos;
		return *this;
	}

	// Position * number
	 Position operator*(const int num) {
		 return sPos * num;
	}

	// Checking two positions are same or not
	bool operator==(const Position& pos) {
		return sPos.x == pos.x && sPos.y == pos.y;
	}

	// Checking two positions aren't same or not
	bool operator!=(const Position& pos) {
		return sPos.x != pos.x || sPos.y != pos.y;
	}
};
