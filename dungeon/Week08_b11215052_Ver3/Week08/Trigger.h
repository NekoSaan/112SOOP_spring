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
	Trigger() : _exp(10) {
		_icon = 'T';
	}
	Trigger(int x, int y) : _exp(10) {
		_pos.x = x;
		_pos.y = y;
		_icon = 'T';
	}
	Trigger(const Trigger& ref) { *this = ref; }

	// Operator overloading
	// Adding up two positions
	Position operator+(const Position& pos) {
		return _pos + pos;
	}

	// Adding up two positions, then assign to l-value
	Trigger& operator+=(const Position& pos) {
		_pos += pos;
		return *this;
	}

	// Substracting two positions
	Position operator-(const Position& pos) {
		return _pos - pos;
	}

	// Substracting two positions, then assign to l-value
	Trigger& operator-=(const Position& pos) {
		_pos -= pos;
		return *this;
	}

	// Position * number
	Position operator*(const int num) {
		return _pos * num;
	}

	// Checking two positions are same or not
	bool operator==(const Position& pos) {
		return _pos.x == pos.x && _pos.y == pos.y;
	}

	// Checking two positions aren't same or not
	bool operator!=(const Position& pos) {
		return _pos.x != pos.x || _pos.y != pos.y;
	}

	void update(Hero& hero) {
		if (hero.getPos().x == _pos.x && hero.getPos().y == _pos.y && !(hero != _pos)) {
			hero.gainEXP(_exp);
		}

		Position testCase(1, 1);
		
		// checking operator overloading working
		_pos = *this + testCase;
		*this += testCase;
		_pos = *this - testCase;
		*this -= testCase;
		_pos = *this * 1;
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

