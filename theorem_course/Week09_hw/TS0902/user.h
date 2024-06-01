/************************************************************************
File:
		Namespace.cpp
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
#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string>

namespace Authenticate
{
	// input username
	void inputUserName(void);

	// Get username
	std::string getUserName(void);
}

#endif // _USER_H_