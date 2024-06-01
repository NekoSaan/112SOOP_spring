/************************************************************************
File:
		File.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Declare File class
************************************************************************/
#ifndef _FILE_H_
#define _FILE_H_
#include "Document.h"

// File class, inherti Document
class File : public Document {
private:
	string pathName;

public:
	// Default Constructor
	File(string text, string fileName) : Document::Document(text), pathName(fileName) {};

	// Set path name
	void setPathname(string);

	// Get path name
	string getPathname(void);
};

#endif // _FILE_H_