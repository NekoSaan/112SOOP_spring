/***********************************************************************
 * File:
        Leaderboard.cpp
 * Author:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
        2024/02/28
 * Editor:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
        2024/02/28
 * Description:
        Consider a text file named scores.txt that contains player scores for a game.
        A possible sample is shown next where Ronaldo's best score is 10400,
        Didie's best score is 9800, etc. Put at least five names and scores in the file.
***********************************************************************/
#include <iostream> // For cout.
#include <fstream> // For file I/O operations.
#include <string> // For string format.
#include <vector> // For vector format.

using namespace std;

void getHighScores(vector<string> names, vector<int> scores); // Function prototype.

int main(void)
{
    fstream f = fstream("scores.txt", ios::in); // Open the scores.txt.
    vector<string> names; // Create a vector to store names.
    vector<int> vec; // Create a vector to store scores.

    // Read the file until EOF.
    while (!f.eof())
    {
        string name;
        int score;

        f >> name >> score;

        names.push_back(name);
        vec.push_back(score);
    }

    f.close();

    getHighScores(names, vec);
}

//******************************************************************
//
// * Find the top 3 players.
//==================================================================
void getHighScores(vector<string> names, vector<int> scores)
{
    //==================================================================
        // Find the top 3 players.
    for (int i = 0; i < 3; i++)
    {
        int idx = i;

        // Find the highest score each time.
        for (int j = 0; j < scores.size(); j++)
        {
            if (scores[j] > scores[idx])
            {
                idx = j;
            }
        }

        cout << names[idx] << endl << scores[idx] << endl;
        scores[idx] = 0; // Set the highest score to 0.
    }
}