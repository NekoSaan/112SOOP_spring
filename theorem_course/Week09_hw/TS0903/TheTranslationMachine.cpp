/************************************************************************
File:
		TheTranslationMachine.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/16
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/17
Description:
		Here is a translation machine. You are given the possible translations
		of letters and a list of pairs of original and deciphered words.
		Your task is to verify whether the words in each pair match.
		Two words match if they have the same length and if each letter
		of the first word can be turned into the corresponding letter of
		the second word by using the available translations zero or more times.
************************************************************************/
#include <iostream> // cin & cout
#include <vector> // vector structure
#include <algorithm>

using namespace std;

// using recursive to translate all possible result
bool translation(char, char);

// translate table / hashmap
vector<pair<char, char>> m;

// record list
vector<char> recLists;

int main(void) {
	int M, N;

	// read until M, N both equal to 0
	while (cin >> M >> N) {
		if (!M && !N) {
			break;
		}

		// clear last testcase data
		m.clear();

		// insert translate table
		for (int i = 0; i < M; i++) {
			char origin, encrypt;
			cin >> origin >> encrypt;

			m.push_back(make_pair(origin, encrypt));
		}

		// testcase input & validiate
		while (N--) {
			string str, goal;
			cin >> str >> goal;

			// if table is not empty & the length of two string are same.
			// start translation process
			if ((str.length() == goal.length()) && !m.empty()) {
				bool res = true;

				// translate each character, if one of string can't be translated
				// end progress, and set result to false
				for (int i = 0; i < str.length(); i++) {
					// clear last char's data
					recLists.clear();

					if (!translation(str[i], goal[i])) {
						res = false;
						break;
					}
				}

				// print message accroding to translation result
				if (res) {
					cout << "yes" << endl;
				}
				else {
					cout << "no" << endl;
				}
			}
			else {
				// Different length of string are impossible to translate
				cout << "no" << endl;
			}
		}
	}
}

// Intent: Using recursive to find all possible result
// Pre: translate table/hashmap
// Post: return a bool value accroding to the translate result
// \param cur : current character be translated into
// \param target : our translate target
bool translation(char cur, char target) {
	// if cur == target, infers that translation success
	if (cur == target) {
		return true;
	}

	// try any possible translation path, once the translation success
	// return true immdiately
	for (int i = 0; i < m.size(); i++) {
		if (cur == m[i].first && find(recLists.begin(), recLists.end(), m[i].second) == recLists.end()) {
			recLists.push_back(cur);

			if (translation(m[i].second, target)) {
				return true;
			}
		}
	}

	// otherwise, return false
	return false;
}