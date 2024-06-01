/************************************************************************
File:
		password.cpp
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
#include "password.h"

namespace {
	std::string password;

	// Intent: Validiate password
	// Pre: password
	// Post: return a bool value accroding to password is valid or not.
	bool isValid(void) {
		if (password.length() < 8) {
			return false;
		}

		// check is there at least 1 digit or not
		for (char& c : password) {
			if (isdigit(c)) {
				return true;
			}
		}

		return false;
	}
}

// Intent: input password
// Pre: None
// Post: password is setup
void Authenticate::inputPassword(void) {
	// read until valid input
	do {
		std::cout << "Enter your password (at least 8 characters";
		std::cout << " and at least one non-letter)" << std::endl;

		std::cin >> password;
	} while (!isValid());
}

// Intent: Get password
// Pre: password
// Post: return password
std::string Authenticate::getPassword(void) {
	return password;
}