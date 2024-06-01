/************************************************************************
File:
        main.cpp
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
#include <iostream>
#include "Account.h"

using namespace std;

int main(void) {
    Account a(100);

    try {
        cout << "Depositing 50" << endl;
        cout << "New balance: " << a.deposit(50) << endl;

        cout << "Withdraw 25" << endl;
        cout << "New balance: " << a.withdraw(25) << endl;

        cout << "Withdraw 250" << endl;
        cout << "New balance: " << a.withdraw(250) << endl;

        /*
        cout << "Depositing -50" << endl;
        cout << "New balance: " << a.deposit(-50) << endl;
        */
    }
    catch (InsufficientFunds) {
        cout << "Not enough money to withdraw that amount." << endl;
    }
    catch (NegativeDeposit) {
        cout << "You may only deposit a positive amount." << endl;
    }

    cout << "Enter a character to exit" << endl;

    char wait;
    cin >> wait;
}
