/************************************************************************
File:
		main.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/05/21
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/05/21
Description:
		Consider a text file of names with one name per line, and the names
		have been collected from several different sources.
************************************************************************/
#include <iostream>	// for cin & cout
#include <fstream>	// for file manage
#include <string>	// for string format
#include <set>		// for set format
using namespace std;

int main(void) {
	// open invitation list
	ifstream f("name.txt", ios::in);

	// declare set to store non-repeat invitation list
	set<string> list;

	// declare 1 string variable to store current name
	string s;

	// read until EOF, insert each into set, repeat name will automatically omit
	while (getline(f, s)) {
		list.insert(s);
	}

	f.close(); // close the file

	// print out result
	for (auto& str : list) {
		cout << str << endl;
	}
}