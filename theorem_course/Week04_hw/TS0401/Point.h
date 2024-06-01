#ifndef Point_H
#define Point_H
#include <iostream>

using namespace std;

class Point
{
private:
	int vertical;
	int horizontal;

public:
	Point()
	{
		this->vertical = 0;
		this->horizontal = 0;
	}

	void Set(int vertical, int horizontal);
	void Move(int x, int y);
	void Rotate();
	int RetrieveVertical() const { return this->vertical; }
	int RetrieveHorizontal() const { return this->horizontal; }
};

#endif //Point_H