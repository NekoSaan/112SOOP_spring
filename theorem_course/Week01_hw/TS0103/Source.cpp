#include <iostream>

using namespace std;

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 7 - i; j > 0; j--)
		{
			cout << ' ';
		}
		cout << '*' << endl;
	}

	cout << "*   *" << endl;
	cout << " * *" << endl;
	cout << "  *" << endl;

	return 0;
}