/************************************************************************
File:
		Document.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Declare Document class
************************************************************************/
#ifndef _DOC_H_
#define _DOC_H_
#include <string>
using namespace std;

// Document Class
class Document {
protected:
	string text; // text variable

public:
	// Default Constructor
	Document(string text) : text(text) {};

	// Get context of text
	string getText(void) const;

	// Assign operator overloading
	Document& operator=(Document d);
};

#endif // _DOC_H_