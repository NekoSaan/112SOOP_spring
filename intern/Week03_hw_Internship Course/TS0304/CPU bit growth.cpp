/************************************************************************
File:
        CPU bit growth.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/06
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/07
Description:
        There is a given year Y, find the maximum positive integer N where N!
        is within the CPU calculation range of the current year.
************************************************************************/
#include <iostream> // For print out information
#include <cmath> // For log() function.

using namespace std;

int main(void)
{
    unsigned int Y; // A variable to store the input year, reusable.

    // While the input is not the end of file, keep reading the input.
    while (cin >> Y && !cin.eof())
    {
        // Calculate the bit of CPU, 2^((Y - 1880) / 10).
        unsigned long long bit = pow(2, ((Y - 1880) / 10));

        // Calculate the CPU process. To simplify the calculation, we use log();
        long double cpuProcess = log(2) * bit;

        unsigned int N = 1;
        long double factorial = 0;

        // Calculate the factorial until it is larger than the CPU process.
        while (factorial <= cpuProcess)
        {
            factorial += log(++N);
        }

        cout << N - 1 << endl;
    }
}