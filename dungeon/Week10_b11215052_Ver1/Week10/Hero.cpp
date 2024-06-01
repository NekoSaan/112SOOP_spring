#include "Hero.h"

void Hero::move(Position delta) {
	// Compute the next position
	Position next = this->sPos + delta;

	if (isPositionValid(next))
		this->sPos = next;
	else {
		std::cout << "Invalid location\n";
	}
}