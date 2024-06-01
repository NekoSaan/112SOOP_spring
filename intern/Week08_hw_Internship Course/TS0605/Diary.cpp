/************************************************************************
File:
		Diary.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/10
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/11
Description:
		You are making observations on several unknown creatures and you
		need to record the number of various body parts of them
		(e.g. How many legs, tails...) and generate diary observation logs.

		You feel that manual diary logging is too cumbersome and want to
		design a program to automatically generate logs. You plan to design
		two classes Diary and Creature to handle this.
************************************************************************/
#include "Diary.h"

// Start a new day
void Diary::NewDay(string input) {
	day_log new_day;
	new_day.name = input;
	day.push_back(new_day);
}

// Logging a new event
void Diary::NewEvent(string creature_name, string input) {
	event new_event;
	new_event.name = creature_name;
	new_event.content = input;
	day[day.size() - 1].event_list.push_back(new_event);
}