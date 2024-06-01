#include "HotDogStand.h"

// init total sell amount
int HotDogStand::totalSellAmount = 0;

// Default Constructor
HotDogStand::HotDogStand()
{
	this->standId = "";
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char *id)
{
	this->standId = id;
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	this->standId = id;
	this->hotDogSellAmount = amount;
	totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{

}

void HotDogStand::justSold()
{
	this->hotDogSellAmount++;
	totalSellAmount++;
}

void HotDogStand::print()
{
	cout << this->standId << " " << this->hotDogSellAmount << endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}