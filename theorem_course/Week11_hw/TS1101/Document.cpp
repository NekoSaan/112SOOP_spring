/************************************************************************
File:
		Document.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Define Document class
************************************************************************/
#include "Document.h"

// Intent: return context of Document
// Pre: context of Document
// Post: variable returned
string Document::getText(void) const { return text; }

// Intent: Assign operator overloading
// Pre: Another right-value document
// Post: Document variable assigned
// \param d: another document
Document& Document::operator=(Document d) {
	this->text = d.text;

	return *this;
}