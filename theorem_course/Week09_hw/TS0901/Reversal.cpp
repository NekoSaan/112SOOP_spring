/************************************************************************
File:
		Reversal.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/16
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/16
Description:
		The text file words.txt, which is included, contains an alphabetically
		sorted list of English words.

		Note that the words are in mixed upper and lowercase.
************************************************************************/
#include <iostream> // for cin & cout
#include <vector> // vector structure
#include <string> // for string format and relative functions
#include <algorithm> // for find()

using namespace std;

int main(void) {
	vector<string> list; // words list
	string buf;

	// read until EOF
	while (cin >> buf) {
		// change each chars to lowercase
		transform(buf.begin(), buf.end(), buf.begin(), ::tolower);

		list.push_back(buf);
	}

	buf = "";

	// finding longest reversal
	for (string& s : list) {
		string tmp = s; // store original word
		reverse(tmp.begin(), tmp.end()); // reversing word

		// searching for reversed word, if exits and its length > current length
		// then renew the result
		auto found = find(list.begin(), list.end(), tmp);

		if (found != list.end() && *found != s && tmp.length() > buf.size()) {
			buf = tmp;
		}
	}

	cout << buf;
}