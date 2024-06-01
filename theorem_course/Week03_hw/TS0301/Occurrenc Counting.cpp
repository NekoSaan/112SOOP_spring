/************************************************************************
File:
        Occurrenc Counting.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/06
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/06
Description:
         Reads a list of numbers with an integer type and counts how many
         times each number appears.
************************************************************************/
#include <iostream> // For cin, cout, endl
#include <unordered_map> // For unordered_map
#include <vector> // For vector
#include <algorithm> // For find, sort

using namespace std;

int main(void)
{
    int n; // Variable to read input, reusable.
    unordered_map<int, int> m; // Hash_Map to store the number and its count.

    vector<int> v; // Vector to store the number in order.

    // Read until the end of file.
    while (cin >> n && !cin.eof())
    {
        m[n]++; // Increase the occurrence of the number.

        // If the number is not in the order, add it.
        if (find(v.begin(), v.end(), n) == v.end())
        {
            v.push_back(n);
        }
    }

    // Sort the number in order.
    sort(v.begin(), v.end());

    //  Reverse the order to print the number in descending order.
    reverse(v.begin(), v.end());

    cout << "N\tcount\n";

    // Print the number and its occurrence.
    for (auto i : v)
    {
        cout << i << "\t" << m[i] << endl;
    }
}