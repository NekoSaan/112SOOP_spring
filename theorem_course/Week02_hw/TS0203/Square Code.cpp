/***********************************************************************
 * File:
        Square Code.cpp
 * Author:
        Kuo Po Wei�Apowei30445@gmail.com
 * Create Date:
        2024/02/28
 * Editor:
        Kuo Po Wei�Apowei30445@gmail.com
 * Update Date:
        2024/02/28
 * Description:
        The input messages of each line are English characters without spaces.
        Try to put the characters into a n*n square. Note that (n-1)^2 < message length <= n^2.
***********************************************************************/
#include <iostream> // For cin, cout.
#include <string> // For string format.

using namespace std;

int main(void)
{
    string s; // The input message, reusable.

    while (cin >> s && !cin.eof())
    {
        int n; // Variable to store the minimum n.

        // Find the minimum n that satisfies (n-1)^2 < message length <= n^2.
        for (n = 1; n * n < s.length(); n++);

        // Output the message in a n * n square.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + j * n < s.length())
                {
                    cout << s[i + j * n];
                }
            }
            cout << endl;
        }
    }
}