/************************************************************************
File:
		File.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Define File class
************************************************************************/
#include "File.h"

// Intent: return context of Document
// Pre: context of Document
// Post: variable returned
// \param newName: file's new path name
void File::setPathname(string newName) {
	this->pathName = newName;
}

// Intent: return context of path name
// Pre: context of path name
// Post: path name returned
string File::getPathname(void) {
	return this->pathName;
}