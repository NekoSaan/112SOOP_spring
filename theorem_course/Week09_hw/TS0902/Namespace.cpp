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
		2024/04/16
Description:
		This Programming Project explores how the unnamed namespace works.
************************************************************************/
#include "user.h"
#include "password.h"

using namespace Authenticate;

int main(void)
{
	inputUserName();
	inputPassword();

	std::cout << "Your username is " << getUserName();
	std::cout << " and your password is: " << getPassword() << std::endl;

	return 0;
}