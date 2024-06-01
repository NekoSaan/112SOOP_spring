/************************************************************************
File:
		user.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/16
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/17
Description:
		This Programming Project explores how the unnamed namespace works.
************************************************************************/
#include "user.h"

namespace {
	std::string username;

	// Intent: Validiate username
	// Pre: username
	// Post: return a bool value accroding to username is valid or not.
	bool isValid(void) {
		// Each chars should be alphabet
		for (char& c : username) {
			if (!isalpha(c)) {
				return false;
			}
		}

		return username.length() == 8;
	}
}

// Intent: input username
// Pre: None
// Post: username is setup
void Authenticate::inputUserName(void) {
	// read until valid input
	do {
		std::cout << "Enter your username (8 letters only)" << std::endl;
		std::cin >> username;
	} while (!isValid());
}

// Intent: Get username
// Pre: username
// Post: return username
std::string Authenticate::getUserName(void) {
	return username;
}