/************************************************************************
File:
		Diary.h
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
#ifndef _DIARY_H_
#define _DIARY_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Event structure
typedef struct Event {
	string name;
	string content;
} event;

// Day log structure
typedef struct Day_Log {
	string name;
	vector<event> event_list;
} day_log;

// Diary Class
class Diary {
public:
	// Start a new day
	static void NewDay(string input);

	// Logging a new event
	static void NewEvent(string creature_name, string input);

	// Day log (static variable)
	static vector<day_log> day;
};

#endif // _DIARY_H_