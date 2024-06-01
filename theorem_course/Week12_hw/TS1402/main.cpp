/************************************************************************
File:
        main.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/05/08
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/05/08
Description:
        Write a main program that creates three types of school
        (one from each class: School, PrivateSchool, and PublicSchool)
        and transfers students from each to another one.
************************************************************************/
#include "School.h"

int main(void) {
    //init 3 different account types
    School ntust("NTUST", 12500);
    PublicSchool ntut("NTUT", 85000);
    PrivateSchool fjcu("FJCU", 25000);

    //state info all 3
    cout << ntust << endl;
    cout << ntut << endl;
    cout << fjcu << endl;

    //test all methods on School
    ntust.admissions(200);
    cout << ntust << endl;

    ntust.dropouts(200);
    cout << ntust << endl;

    ntust.dropouts(100000);
    cout << ntust << endl;

    //test all methods on PrivateSchool
    fjcu.admissions(1000);
    cout << fjcu << endl;

    fjcu.dropouts(50);
    cout << fjcu << endl;

    fjcu.dropouts(1000);
    cout << fjcu << endl;

    //test all methods on PublicSchool
    ntut.admissions(1000);
    cout << ntut << endl;

    ntut.apply_growth();
    cout << ntut << endl;

    ntut.dropouts(1000);
    cout << ntut << endl;

    //Transfer method
    cout << ntut << endl;
    ntut.transfer(1000, ntust);
    cout << ntut << endl;
    cout << ntust << endl;

    fjcu.transfer(30000, ntust);
    cout << fjcu << endl;
    cout << ntust << endl;

    return 0;

}
