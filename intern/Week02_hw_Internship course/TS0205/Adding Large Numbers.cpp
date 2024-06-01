/***********************************************************************
 * File:
        Adding Large Numbers.cpp
 * Author:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
        2024/02/28
 * Editor:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
        2024/02/28
 * Description:
        Given two integers A, B. Please calculate the adding result of A+B,
        notice that the maximum bits of the number can approximate to 10000.
***********************************************************************/
#include <iostream> // For cin, cout.
#include <string> // For string format

using namespace std;

// Define a struct to store the big integer.
typedef struct bigInt
{
    string number = "";
} BigInt;

BigInt Add(const BigInt& lhs, const BigInt& rhs); // Add two big integers.

int main(void)
{
    int n; // The number of test cases.
    cin >> n;

    while (n--)
    {
        BigInt a, b; // Variables to store the big integers.

        cin >> a.number >> b.number;

        BigInt result = Add(a, b); // Add them up.

        cout << result.number << endl;
    }
}

BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
    BigInt result;

    int carry = 0; // The carry flag.
    int i = lhs.number.size() - 1, j = rhs.number.size() - 1;

    // Process the addition from the end of the string.
    while (i >= 0 || j >= 0)
    {
        int sum = carry;

        if (i >= 0)
        {
            if (lhs.number[i] < '0' || lhs.number[i] > '9')
            {
                result.number = "Not a valid number, please try again.";
                return result;
            }

            sum += lhs.number[i--] - '0';
        }

        if (j >= 0)
        {
            if (rhs.number[j] < '0' || rhs.number[j] > '9')
            {
                result.number = "Not a valid number, please try again.";
                return result;
            }

            sum += rhs.number[j--] - '0';
        }

        // Place this bit's result to the front of the string.
        result.number = to_string(sum % 10) + result.number;

        carry = sum / 10; // Update the carry flag.
    }

    // If there is a carry at the end, add it to the front of the string.
    if (carry)
    {
        result.number = to_string(carry) + result.number;
    }

    return result;
}