/************************************************************************
File:
        textBasedHistogram.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/03/06
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/03/06
Description:
        Generate a text-based histogram for a quiz of students.
        The quiz is graded on a scale from 0 to 5.
************************************************************************/
#include <iostream> //  For input and output.
#include <fstream> // For file operation.

using namespace std;

int main(void)
{
    ifstream f1; // variable for grade.txt
    ofstream f2; // variable for grades.Output

    f1.open("grade.txt", ios::in);
    f2.open("grades.Output", ios::out);

    int freq[6] = { 0 }; // Declare an array to store the frequency of each grade.
    int tmp; // Declare a variable to store data.

    // Read the grades from the file and count the frequency of each grade.
    while (f1 >> tmp)
    {
        freq[tmp]++;
    }

    // Write the frequency of each grade to the file.
    for (int i = 0; i < 6; i++)
    {
        f2 << freq[i] << " grade(s) of " << i << endl;
    }

    f1.close();
    f2.close();
}