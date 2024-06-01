#ifndef Point_H
#define Point_H
#include <iostream>

using namespace std;

class Point {
private:
	int vertical;
	int horizontal;

public:
	// Default Constructor
	Point()
	{
		this->vertical = 0;
		this->horizontal = 0;
	}

	// Copy Constructor
	Point(Point& point)
	{
		this->vertical = point.vertical;
		this->horizontal = point.horizontal;
	}

	// Set point directly
	void Set(int vertical, int horizontal);

	// Point movement
	void Move(int x, int y);

	// Rotate & Reflect
	void Rotate();
	void Reflect();

	// Get vertical element
	int GetVertical() const { return this->vertical; }

	// Get horizontal element
	int GetHorizontal() const { return this->horizontal; }
};

#endif //Point_H