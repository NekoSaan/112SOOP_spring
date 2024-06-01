/************************************************************************
File:
        Seven-segment.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/26
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/27
Description:
        Write a program that allowed users to input a string and then print
        the number characters with the style of seven-segment display.
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format
#include <vector> // for vector format

using namespace std;

// 七段顯示器真值表
int num[10][7] = { {1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0},
                {1,1,0,1,1,0,1},
                {1,1,1,1,0,0,1},
                {0,1,1,0,0,1,1},
                {1,0,1,1,0,1,1},
                {1,0,1,1,1,1,1},
                {1,1,1,0,0,0,0},
                {1,1,1,1,1,1,1},
                {1,1,1,1,0,1,1} };

int main()
{
    string str;

    // read until EOF
    while (getline(cin, str)) {
        vector<int> order;

        for (char& c : str)
        {
            if (isdigit(c)) order.push_back(c - '0');
        }

        for (auto& i : order)
        {
            if (num[i][0]) cout << " _ ";
            else cout << "   ";
        }

        cout << endl; // change the line

        for (auto& i : order)
        {
            if (num[i][5]) cout << "|";
            else cout << " ";

            if (num[i][6]) cout << "_";
            else cout << " ";

            if (num[i][1]) cout << "|";
            else cout << " ";
        }

        cout << endl; // change the line

        for (auto& i : order)
        {
            if (num[i][4]) cout << "|";
            else cout << " ";

            if (num[i][3]) cout << "_";
            else cout << " ";

            if (num[i][2]) cout << "|";
            else cout << " ";
        }

        cout << endl; // change the line
    }
}