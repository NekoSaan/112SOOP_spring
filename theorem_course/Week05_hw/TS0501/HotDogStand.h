#ifndef HOT_DOG_STAND_H
#define HOT_DOG_STAND_H
#pragma once
#include <iostream>
using namespace std;


//******************************************************************
//
// * Hot dog stand Class.
//==================================================================
class HotDogStand {
private:
	const char* standId;
	int hotDogSellAmount;
	static int totalSellAmount;

public:
	// Default Constructor
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);

	// Default Destructor
	~HotDogStand();

	// action
	void justSold();
	void print();

	// Get current sell amount of the Stand.
	int thisStandSoldAmount();

	// Get total sell amount of all.
	static int allStandSoldAmount();
};

#endif