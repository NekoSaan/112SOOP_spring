#include "Point.h"

// Set point directly
void Point::Set(int horizontal, int vertical)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

// Point movement
void Point::Move(int y, int x)
{
	this->vertical += x;
	this->horizontal += y;
}

// Rotating the x-y plot 90 degree.
void Point::Rotate()
{
	// swapping x, y
	this->vertical ^= this->horizontal;
	this->horizontal ^= this->vertical;
	this->vertical ^= this->horizontal;

	// vertical componet * -1, since the -sin(2/pi) = -1
	this->vertical *= -1;
}

// Reflecting the x-y plot.
void Point::Reflect()
{
	this->vertical *= -1;
	this->horizontal *= -1;
}