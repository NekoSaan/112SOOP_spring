/************************************************************************
File:
		Creature.cpp
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
#include "Creature.h"

// initialize day log
vector<day_log> Diary::day;

// Compare two string size, sort function/method
bool compare_string(body_parts a, body_parts b) {
	return a.name < b.name;
}

// Constructor
Creature::Creature(string name) {
	this->name = name;

	// Set start day = current day
	start_day_index = Diary::day.size() - 1;
}

// Copy Constructor
Creature::Creature(string name, Creature base) {
	this->name = name;
	body = base.body;

	// Set start day = current day
	start_day_index = Diary::day.size() - 1;
}

// Operators Overloading
// return reference accroding to index []
Creature& Creature::operator[](string target) {
	// searching target. if exists, 
	// set index to it then return it (Creature&)
	for (size_t i = 0; i < body.size(); i++) {
		if (target == body[i].name) {
			index = i;
			return *this;
		}
	}

	// Otherwise, adding new body type and set index to it
	index = body.size();
	body_parts new_part;
	new_part.name = target;
	new_part.amount = 0;
	body.push_back(new_part);

	return *this;
}

// Assignment
Creature& Creature::operator=(int input) {
	string output = "'s " + body[index].name;

	if (!body[index].amount && input) {
		output += " appeared (";
	}
	else if (input == 0 && body[index].amount == 0) {
		return *this;
	}
	else if (input > body[index].amount) {
		output += " increased (";
	}
	else if (input < body[index].amount) {
		output += " decreased (";
	}
	else {
		return *this;
	}

	output = output + to_string(body[index].amount) + " -> ";
	body[index].amount = input;
	output = output + to_string(body[index].amount) + ").";
	Diary::NewEvent(name, output);

	return *this;
}

// Addition (body part & its amount)
Creature& Creature::operator+=(int input) {
	return ((*this) = ((*this) + input));
}

int Creature::operator+(int input) {
	return body[index].amount + input;
}

// Substraction (body part & its amount)
Creature& Creature::operator-=(int input) {
	return ((*this) = ((*this) - input));
}

int Creature::operator-(int input) {
	return body[index].amount - input;
}

// print status
void Creature::PrintStatus(void) {
	// sort by name
	sort(body.begin(), body.end(), compare_string);

	cout << name << "'s status:" << endl;
	
	// iterate each body parts. if amount != 0, print it
	for (int i = 0; i < body.size(); i++) {
		if (body[i].amount != 0) {
			cout << body[i].name << " * " << body[i].amount << endl;
		}
	}

	cout << endl;
}

// print day log
void Creature::PrintLog(void) {
	cout << name << "'s log:" << endl;

	// iterate each day
	for (int i = start_day_index; i < Diary::day.size(); i++) {
		cout << "Day " << Diary::day[i].name << endl;

		// iterate each event
		for (int j = 0; j < Diary::day[i].event_list.size(); j++) {
			if (Diary::day[i].event_list[j].name == name) {
				cout << name << Diary::day[i].event_list[j].content << endl;
			}
		}
	}

	cout << endl;
}