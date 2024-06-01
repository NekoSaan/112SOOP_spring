#pragma once
//************************************************************
// The location in the board
//************************************************************
class Position {
public:
	int x, y; // x, y Coordinate

	// Default Cosntructor
	Position() : x(0), y(0) {}

	// Constructor
	Position(int x, int y) : x(x), y(y) {}

	// Copy Constructor
	Position(const Position& ref) { *this = ref; }

	// Operator overloading
	// Adding up two positions
	Position operator+(const Position& pos) {
		return Position(x + pos.x, y + pos.y);
	}

	// Adding up two positions, then assign to l-value
	Position& operator+=(const Position& pos) {
		x += pos.x;
		y += pos.y;

		return *this;
	}

	// Substracting two positions
	Position operator-(const Position& pos) {
		return Position(x - pos.x, y - pos.y);
	}

	// Substracting two positions, then assign to l-value
	Position& operator-=(const Position& pos) {
		x -= pos.x;
		y -= pos.y;

		return *this;
	}

	// Position * number
	Position operator*(const int num) {
		return Position(x * num, y * num);
	}

	// Checking two positions are same or not
	friend bool operator==(const Position& pos1, const Position& pos2) {
		return pos1.x == pos2.x && pos1.y == pos2.y;
	}

	// Checking two positions aren't same or not
	friend bool operator!=(const Position& pos1, const Position& pos2) {
		return pos1.x != pos2.x || pos1.y != pos2.y;
	}
};
