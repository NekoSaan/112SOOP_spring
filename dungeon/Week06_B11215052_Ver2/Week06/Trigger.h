#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"

//************************************************************
// Trigger Class
//************************************************************
class Trigger {
private:
	Position _pos;
	char _icon;
	int _exp;

public:
	Trigger(int x, int y, int exp) : _exp(exp) {
		_pos.x = x;
		_pos.y = y;
		_icon = 'T';
	}

	void update(Hero& hero) const {
		if (hero.getPos().x == _pos.x && hero.getPos().y == _pos.y) {
			hero.gainEXP(_exp);
		}
	}

	// Set position
	void setPos(const Position& pos) { this->_pos = pos; }
	void setPos(int x, int y) {
		this->_pos.x = x;
		this->_pos.y = y;
	}

	// Get position
	Position getPos() const { return this->_pos; }

	// Get Icon
	char getIcon() const { return this->_icon; }

	int getExpAmount() const { return this->_exp; }
};