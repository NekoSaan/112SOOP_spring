/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/19
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/19
Description:
		Your boss has a hot dog chain in the city, and he needs your help
		to manage his hot dog stores.
************************************************************************/
#include "HotDogStand.h"

int main() {
	HotDogStand stand1("Stand1", 0);
	HotDogStand stand2("Stand2", 100);
	HotDogStand stand3("Stand3");
	stand1.justSold();
	stand2.justSold();
	stand3.justSold();
	stand1.print();
	stand2.print();
	stand3.print();
	cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
	return 0;
}