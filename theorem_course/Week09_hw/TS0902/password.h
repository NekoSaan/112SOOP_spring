/************************************************************************
File:
		password.h
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
#ifndef _PASSWD_H_
#define _PASSWD_H_
#include <iostream>
#include <string>

namespace Authenticate 
{
	// input password
	void inputPassword(void);
	
	// Get password
	std::string getPassword(void);
}

#endif // _PASSWD_H_