/***********************************************************************
 * File:
        Compute The Tax.cpp
 * Author:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
        2024/02/28
 * Editor:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
        2024/02/28
 * Description:
        Calculate the tax payable of citizens based on below table.
        Income          Rate
        Not over $750   1% of income
        $750¡X$2,250     $7.50 plus 2% of amount over $750
        $2,250¡X$3,750   $37.50 plus 3% of amount over $2,250
        $3,750¡X$5,250   $82.50 plus 4% of amount over $3,750
        $5,250¡X$7,000   $142.50 plus 5% of amount over $5,250
        Over $7,000     $230.00 plus 6% of amount over $7,000
***********************************************************************/
#include <iostream> // For cin, cout.
#include <iomanip>  // For setprecision.

using namespace std;

int main(void)
{
    float income; // The income of the citizen.

    // Calculate the tax payable of citizens.
    // The tax rate is based on table in the description.
    while (cin >> income && !cin.eof())
    {
        if (income <= 750)
        {
            cout << fixed << setprecision(2) << income * 0.01 << endl;
        }
        else if (income <= 2250)
        {
            cout << fixed << setprecision(2) << 7.50 + (income - 750) * 0.02 << endl;
        }
        else if (income <= 3750)
        {
            cout << fixed << setprecision(2) << 37.50 + (income - 2250) * 0.03 << endl;
        }
        else if (income <= 5250)
        {
            cout << fixed << setprecision(2) << 82.50 + (income - 3750) * 0.04 << endl;
        }
        else if (income <= 7000)
        {
            cout << fixed << setprecision(2) << 142.50 + (income - 5250) * 0.05 << endl;
        }
        else
        {
            cout << fixed << setprecision(2) << 230.00 + (income - 7000) * 0.06 << endl;
        }
    }
}