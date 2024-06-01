/************************************************************************
File:
		Account.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/05/14
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/05/14
Description:
		A function that returns a special error code is usually accomplished
		by throwing an exception.
		The following class maintains an account balance.
************************************************************************/
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

// Exception class for negative deposit
class NegativeDeposit {};

// Exception class for insufficient funds
class InsufficientFunds {};

// Account class
class Account {
private:
	double balance;

public:
	// Default constructor
	Account(void) { balance = 0; }

	// Constructor with initial deposit
	Account(double initialDeposit) { balance = initialDeposit; }

	// Get current balance
	double getBalance(void);

	// returns new balance or throws exception if invalid amount
	double deposit(double amount);

	//return new balance or throw exception if insufficient funds
	double withdraw(double amount);
};

#endif // _ACCOUNT_H_