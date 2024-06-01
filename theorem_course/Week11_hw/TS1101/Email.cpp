/************************************************************************
File:
		Email.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Define Email class
************************************************************************/
#include "Email.h"

// Intent: Get sender
// Pre: content of sender
// Post: sender returned
string Email::getSender(void) { return this->sender; }

// Intent: Get recipent
// Pre: content of recipent
// Post: recipent returned
string Email::getRecipient(void) { return this->recipient; }

// Intent: Get title
// Pre: content of title
// Post: title returned
string Email::getTitle(void) { return this->title; }