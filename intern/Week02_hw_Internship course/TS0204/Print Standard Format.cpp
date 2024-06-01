/***********************************************************************
 * File:
        Print Standard Format.cpp
 * Author:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Create Date:
        2024/02/28
 * Editor:
        Kuo Po Wei¡Apowei30445@gmail.com
 * Update Date:
        2024/02/28
 * Description:
        You are an IT employee in a company.
        Your manager requests you to print out N employee's information,
        and you need to make sure the result remains clean.
        Each employee has three attributes: Name, Salary and Bonus.
***********************************************************************/
#include <iostream> // For cin, cout.
#include <string> // For string format.
#include <vector> // For vector format.

using namespace std;

int main(void)
{
    int n; // Variable for the number of employees, reusable.

    // read the number of employees until EOF.
    while (cin >> n && !cin.eof())
    {
        // Declare variables to store the number of employees, salary, and bonus.
        size_t m_n = 0, m_s = 0, m_b = 0;

        vector<string> names, salaries, bonuses; // Declare vectors to store the employee's information.

        // Read the employee's information.
        // Meanwhile, find the maximum length of the name, salary, and bonus.
        for (size_t i = 0; i < n; i++)
        {
            string name, salary, bonus; // Variables to store employee's information.

            cin >> name >> salary >> bonus;

            // Find the maximum length of the name, salary, and bonus.
            m_n = max(m_n, name.size());
            m_s = max(m_s, salary.size());
            m_b = max(m_b, bonus.size());

            // Store the employee's information into the vectors.
            names.push_back(name);
            salaries.push_back(salary);
            bonuses.push_back(bonus);
        }

        for (size_t i = 0; i < n; i++)
        {
            cout << string(m_n - names[i].size(), ' ') << names[i] << "|"
                << string(m_s - salaries[i].size() + 2, ' ') << salaries[i] << "|"
                << string(m_b - bonuses[i].size() + 2, ' ') << bonuses[i] << endl;
        }
    }
}