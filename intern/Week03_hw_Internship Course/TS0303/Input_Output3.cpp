/************************************************************************
File:
        Input_Output3.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/06
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/06
Description:
        There is a given arbitrary number X(double), a positive integer M,
        a positive integer N, and a character C.
        Ouput results with restriction.
************************************************************************/
#include <iostream> // For print out information.
#include <iomanip> // For setw, setfill, setprecision, fixed functions.
#include <math.h> // For pow() function.
#include <stdlib.h>
#include <string>
using namespace std;

int main(void)
{
    string str;
    long double X; // A variable to store the input number.
    unsigned int M, N; // Variables to store the width & precision.
    char C; // A variable to store the character.

    while (getline(cin, str))
    {
        char* stop;
        
        X = strtod(str.c_str(), &stop);
        M = strtoul(stop, &stop, 10);
        N = strtoul(stop, &stop, 10);
        C = stop[1];

        // setw to make sure the output is M characters.
        // setprecision to reformat the decimal part of X to N characters.
        // setfill to fill the character C in front of the number.
        // X * 10^n / 10^n to avoid the round() problem.
        cout << setw(M) << setfill(C) << setprecision(N) << fixed
            << (long long int)(X * pow(10, N)) / pow(10, N) << endl;
    }
}