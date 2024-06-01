#include "Month.h"

// Default Constructor
Month::Month()
{
	this->month = 1;
}

// Default Constructor
Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n')
	{
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b')
	{
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r')
	{
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r')
	{
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y')
	{
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n')
	{
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l')
	{
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g')
	{
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p')
	{
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't')
	{
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v')
	{
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c')
	{
		this->month = 12;
	}
	else
	{
		this->month = 1;
	}

}

// Default Constructor
Month::Month(int monthInt)
{
	if (monthInt < 1 || monthInt > 12)
	{
		this->month = 1;
	}
	else
	{
		this->month = monthInt;
	}
}

// Default Destructor
Month::~Month()
{
	
}

// Input an integer as month
void Month::inputInt()
{
	int x;
	cin >> x;

	if (x < 1 || x > 12)
	{
		this->month = 1;
	}
	else
	{
		this->month = x;
	}
}

// Input abbreviation of month.
void Month::inputStr()
{
	char a, b, c;
	cin >> a >> b >> c;

	if (a == 'J' && b == 'a' && c == 'n')
	{
		this->month = 1;
	}
	else if (a == 'F' && b == 'e' && c == 'b')
	{
		this->month = 2;
	}
	else if (a == 'M' && b == 'a' && c == 'r')
	{
		this->month = 3;
	}
	else if (a == 'A' && b == 'p' && c == 'r')
	{
		this->month = 4;
	}
	else if (a == 'M' && b == 'a' && c == 'y')
	{
		this->month = 5;
	}
	else if (a == 'J' && b == 'u' && c == 'n')
	{
		this->month = 6;
	}
	else if (a == 'J' && b == 'u' && c == 'l')
	{
		this->month = 7;
	}
	else if (a == 'A' && b == 'u' && c == 'g')
	{
		this->month = 8;
	}
	else if (a == 'S' && b == 'e' && c == 'p')
	{
		this->month = 9;
	}
	else if (a == 'O' && b == 'c' && c == 't')
	{
		this->month = 10;
	}
	else if (a == 'N' && b == 'o' && c == 'v')
	{
		this->month = 11;
	}
	else if (a == 'D' && b == 'e' && c == 'c')
	{
		this->month = 12;
	}
	else
	{
		this->month = 1;
	}
}

// Output the integer fomat of the month.
void Month::outputInt()
{
	cout << this->month;
}

// Output abbreviation of the month.
void Month::outputStr()
{
	switch(this->month)
	{
		case 1:
			cout << "Jan";
			break;
		case 2:
			cout << "Feb";
			break;
		case 3:
			cout << "Mar";
			break;
		case 4:
			cout << "Apr";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "Jun";
			break;
		case 7:
			cout << "Jul";
			break;
		case 8:
			cout << "Aug";
			break;
		case 9:
			cout << "Sep";
			break;
		case 10:
			cout << "Oct";
			break;
		case 11:
			cout << "Nov";
			break;
		case 12:
			cout << "Dec";
			break;
	}
}

// Return the next month.
Month Month::nextMonth()
{
	return Month((this->month + 1) % 13);
}
