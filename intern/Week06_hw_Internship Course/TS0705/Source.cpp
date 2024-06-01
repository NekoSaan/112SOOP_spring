/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/26
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/27
Description:
		Please write a program that helps Dr. Vine verify his hypothesis.
		This problem statement describes how he thinks the tablets should
		be interpreted. 
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format
#include <map> // for map structure

using namespace std;

// it seems like 4 bits addition
// convert Cow numerals & Arabic numerals to each other's dictionary / hashmap
map<char,int> cowNum_to_num = { { 'V', 0 }, { 'U', 1 }, { 'C', 2 }, { 'D', 3 } };
map<int,char> num_to_cowNum = { { 0, 'V' }, { 1, 'U' }, { 2, 'C' }, { 3, 'D' } };

// Operation A causes Num2 to become the "sum" of Num1 and Num2,
void add(string& n1, string& n2);

// Operation R causes Num2 to have its symbols shifted right one position
void rightShift(string& n);

// Operation L causes Num2 to have its symbols shifted left one position
void leftShift(string& n);

int main(void)
{
	int n; // Number of tablets
	
	while (cin >> n)
	{
		cout << "COWCULATIONS OUTPUT" << endl;

		while (n--)
		{
			string cowNum1, cowNum2, cowAns; // variables to store cow number
			char ops[3]; // array to store 3 operators

			// input cowNums and operators, also the answer
			cin >> cowNum1 >> cowNum2;

			for (int i = 0; i < 3; i++) cin >> ops[i];

			cin >> cowAns;

			// make use of 8 symbols
			while (cowNum1.length() != 8)
			{
				cowNum1 = "V" + cowNum1;
			}

			while (cowNum2.length() != 8)
			{
				cowNum2 = "V" + cowNum2;
			}

			// deal with three operations
			for (int i = 0; i < 3; i++)
			{
				if (ops[i] == 'A') {
					add(cowNum1, cowNum2);
				}
				else if (ops[i] == 'R') {
					rightShift(cowNum2);
				}
				else if (ops[i] == 'L') {
					leftShift(cowNum2);
				}
			}

			// check the cowNum2 is as same as cowAns or not.
			if (!strcmp(cowNum2.c_str(), cowAns.c_str()))
			{
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}

		cout << "END OF OUTPUT" << endl;
	}
}

//=======================================================================
//
// * add two numbers up, and assign it to cowNum2
//=======================================================================
void add(string& n1, string& n2)
//=======================================================================
{
	char carry = 'V'; // carry flag
	string res = ""; // buffer before assign to cowNum2

	// add from first digit
	for (int i = 7; i >= 0; i--)
	{
		// carry + n1 + n2
		int sum = cowNum_to_num[carry] + cowNum_to_num[n1[i]] + cowNum_to_num[n2[i]];

		// deal with carry
		res = num_to_cowNum[sum % 4] + res;
		carry = num_to_cowNum[sum / 4];
	}

	// assign to cowNum2
	n2 = res;
}

//=======================================================================
//
// * right shift cowNum2 1 position, fill 'V' from left side
//=======================================================================
void rightShift(string& n)
//=======================================================================
{
	// remove the right side symbol and add 'V' from left
	n.pop_back();
	n = "V" + n;
}

//=======================================================================
//
// * left shift cowNum2 1 position, fill 'V' from right side
//=======================================================================
void leftShift(string& n)
//=======================================================================
{
	// remove the left side symbol and add 'V' from right
	n.erase(0, 1);
	n = n + "V";
}