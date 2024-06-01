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
		Large number computation
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format

using namespace std;

// process the weird number
void preProcess(string& n1, string& n2);

// operations manager
void manager(const string& n1, const string& n2, int sign1, int sign2);

// print summation
string add(const string& num1, const string& num2);

// print diff
void diff(const string& num1, const string& num2);

// print multi
void product(string num1, string num2);

int main(void)
{
	string num1, num2;

	// read until EOF
	while (cin >> num1)
	{
		cin >> num2;

		int sign1 = 0, sign2 = 0; // variables to store sign of numbers

		// recgonize the sign of numbers
		if (num1[0] == '-')
		{
			sign1 = 1;
			num1.erase(0, 1);
		}

		if (num2[0] == '-')
		{
			sign2 = 1;
			num2.erase(0, 1);
		}

		// pre-process
		preProcess(num1, num2);

		// recgonize the 0
		if (num1.empty())
		{
			num1 = "0";
			sign1 = 0;
		}

		if (num2.empty())
		{
			num2 = "0";
			sign2 = 0;
		}

		manager(num1, num2, sign1, sign2);
	}
}

//=======================================================================
//
// * Summation function
//=======================================================================
void preProcess(string& n1, string& n2)
//=======================================================================
{
	// erase additional 0 from the front
	int cnt = 0;

	for (char& c : n1)
	{
		if (c != '0') break;
		cnt++;
	}

	n1.erase(0, cnt);

	// n2 process

	// erase additional 0 from the front
	cnt = 0;

	for (char& c : n2)
	{
		if (c != '0') break;
		cnt++;
	}

	n2.erase(0, cnt);
}

//=======================================================================
//
// * Summation function
//=======================================================================
void manager(const string& n1, const string& n2, int sign1, int sign2)
//=======================================================================
{
	if (sign1 ^ sign2)
	{
		if (sign1 == 0)
		{
			// summation
			diff(n1, n2);

			// difference
			cout << add(n1, n2) << endl;
		}
		else
		{
			// summation
			diff(n2, n1);

			//difference
			cout << "-" << add(n1, n2) << endl;
		}

		// product
		string tmp1 = n1, tmp2 = n2;

		tmp1.erase(0, 1);
		tmp2.erase(0, 1);

		// check is the number 0 or not?
		if (tmp1.empty() || tmp2.empty()) cout << 0 << endl;
		else
		{
			cout << "-";
			product(n1, n2);
		}
	}
	else if (sign1 == 0)
	{
		// summation
		cout << add(n1, n2) << endl;

		// difference
		diff(n1, n2);

		// product
		product(n1, n2);
	}
	else
	{
		// summation
		cout << "-" << add(n1, n2) << endl;

		// difference
		diff(n2, n1);

		// product
		product(n1, n2);
	}
}

//=======================================================================
//
// * Summation function
//=======================================================================
string add(const string& num1, const string& num2)
//=======================================================================
{
	int carry = 0; // carry flag
	int i = num1.size() - 1, j = num2.size() - 1; // iterator

	string res = ""; // a string to store result number

	// add from single-digit
	while (i >= 0 || j >= 0)
	{
		int sum = carry;

		if (i >= 0)
		{
			sum += num1[i--] - '0';
		}

		if (j >= 0)
		{
			sum += num2[j--] - '0';
		}

		// store number digit by digit
		res = to_string(sum % 10) + res;

		carry = sum / 10; // renew the carry flag
	}

	// deal with final carry flag
	if (carry)
	{
		res = to_string(carry) + res;
	}

	// erase additional 0 from the front
	int cnt = 0;

	for (char& c : res)
	{
		if (c != '0') break;
		cnt++;
	}

	res.erase(0, cnt);

	// if the string is empty, means that the number = 0
	if (res.empty()) res = "0";

	return res;
}

//=======================================================================
//
// * Difference function
//=======================================================================
void diff(const string& num1, const string& num2)
//=======================================================================
{
	int carry = 0; // carry flag
	int i = num1.size() - 1, j = num2.size() - 1; // iterator

	string res = ""; // string to store result

	// substract from single-digit
	while (i >= 0 || j >= 0)
	{
		// deal with carry flag
		int digit = -carry;
		carry = 0; // renew it

		if (i >= 0)
		{
			digit += num1[i--] - '0';
		}

		if (j >= 0)
		{
			digit -= num2[j--] - '0';
		}

		// if the frontest digit need to carry too
		// means that the number is negative
		if (i < 0 && j < 0 && digit < 0)
		{
			cout << "-";
			diff(num2, num1);
			return;
		}

		// set carry flag
		if (digit < 0)
		{
			digit += 10;
			carry = 1;
		}

		res = to_string(digit) + res;
	}

	// erase additional 0 from the front
	int cnt = 0;

	for (char& c : res)
	{
		if (c != '0') break;
		cnt++;
	}

	res.erase(0, cnt);

	// if the string is empty, means that the number = 0
	if (res.empty()) res = "0";

	cout << res << endl;
}

//=======================================================================
//
// * Prouduct function
//=======================================================================
void product(string num1, string num2)
//=======================================================================
{
	string res = ""; // string to store final result
	size_t cnt = 0; // digits counter, 10^cnt.

	// start multiplication
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int carry = 0; // carry flag
		string tmp = ""; // store each digit's product's number

		for (int j = num2.size() - 1; j >= 0; j--)
		{
			// compute the product result digit by digit
			int prod = (num2[j] - '0') * (num1[i] - '0') + carry;

			tmp = to_string(prod % 10) + tmp; // store digit
			carry = prod / 10; // set carry flag
		}

		// deal with the final carry flag
		if (carry)
		{
			tmp = to_string(carry) + tmp;
		}

		// deal with digits ( tmp * 10^cnt )
		for (int i = 0; i < cnt; i++)
			tmp += "0";

		// add them up
		res = add(res, tmp);

		cnt++;
	}

	// erase additional 0 from the front
	int count = 0;

	for (char& c : res)
	{
		if (c != '0') break;
		count++;
	}

	res.erase(0, count);

	// if the string is empty, means that the number = 0
	if (res.empty()) res = "0";

	cout << res << endl;
}