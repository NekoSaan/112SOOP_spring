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
		Levenshtein distance is a measurement of the degree of similarity
		between two words. Levenshtein is the minimum number of steps
		consumed by the operation of inserting, deleting, or replacing
		one word into another word.
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format
#include <vector> // for vector structure

using namespace std;

// compute the Levenshtein distance
unsigned int edit_distance(const string& s1, const string& s2);

int main(void)
{
	string str1, str2;

    // read until EOF
	while (getline(cin, str1))
	{
        getline(cin, str2);

        unsigned int distance = edit_distance(str1, str2);

		cout << distance << endl;
	}
}

//=======================================================================
//
// * 萊文斯坦距離演算法，透過動態規劃
//=======================================================================
unsigned int edit_distance(const string& s1, const string& s2)
//=======================================================================
{
	const size_t len1 = s1.size(), len2 = s2.size(); // length of str1, str2
	vector<vector<unsigned int>> dp(len1 + 1, vector<unsigned int>(len2 + 1)); // dp table

	// init dp table
	dp[0][0] = 0;

	for (unsigned int i = 1; i <= len1; i++)
		dp[i][0] = i;

	for (unsigned int i = 1; i <= len2; i++)
		dp[0][i] = i;

	for (unsigned int i = 1; i <= len1; i++)
		for (unsigned int j = 1; j <= len2; j++)
		{
			// 從上到下分別為 insert, delete, alternate 需花的步數
			dp[i][j] = min(dp[i - 1][j] + 1, min(
						   dp[i][j - 1] + 1,
						   dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)));
		}


	return dp[len1][len2];
}

/*

 alternate | insert
	delete |

example:

	X X s i t t i n g
	X 0 1 2 3 4 5 6 7
	k 1 1 2 3 4 5 6 7
	i 2 2 1 2 3 4 5 6
	i 3 3 2 2 3 3 4 5
	t 4 4 3 2 2 3 4 5
	t 5 5 4 3 2 3 4 5
	e 6 6 5 4 3 3 4 5
	n 7 7 6 5 4 4 3 4
*/