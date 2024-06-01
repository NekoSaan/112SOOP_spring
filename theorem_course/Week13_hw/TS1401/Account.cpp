/************************************************************************
File:
        Account.cpp
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
#include "Account.h"

// Intent: Get the current balance
// Pre: None
// Post: The current balance is returned
double Account::getBalance(void) { return balance; }

// Intent: Deposit money into the account
// Pre: amount is the amount to deposit
// Post: The amount is deposited into the account
// \param amount: the amount to deposit
double Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        throw NegativeDeposit();
    }

    return balance;
}

// Intent: Withdraw money from the account
// Pre: amount is the amount to withdraw
// Post: The amount is withdrawn from the account
// \param amount: the amount to withdraw
double Account::withdraw(double amount) {
    if ((amount > balance) || (amount < 0)) {
        throw InsufficientFunds();
    }
    else {
        balance -= amount;
    }

    return balance;
}