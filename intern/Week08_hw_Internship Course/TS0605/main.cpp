/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/10
Description:
		You are making observations on several unknown creatures and you
		need to record the number of various body parts of them 
		(e.g. How many legs, tails...) and generate diary observation logs. 

		You feel that manual diary logging is too cumbersome and want to
		design a program to automatically generate logs. You plan to design
		two classes Diary and Creature to handle this.
************************************************************************/
#include "Diary.h"
#include "Creature.h"

int main() {
	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 26;
	unknownA.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA.PrintLog();
}
