/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/19
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/20
Description:
		Write a program that records at most 10 student data by structures.
************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// students' record structure
typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

// print out the record.
void print(vector<StRec>& recs);

// insert data.
void insert(vector<StRec>& recs, StRec buffer);

// delete data.
void del(vector<StRec>& recs, StRec target);

//search data.
int search(vector<StRec>& recs, StRec target);

int main(void)
{
	vector<StRec> recs; // list of records
	string command; // variable to recgonize command
	
	// read command until EOF
	while (cin >> command)
	{
		// print command
		if (command == "print")
		{
			print(recs);
			continue;
		}

		StRec buffer; // Structure buffer

		// data input
		cin >> buffer.firstName >> buffer.lastName >> buffer.phone;

		// Actions accroding to command.
		if (strlen(buffer.firstName) > 25 || strlen(buffer.lastName) > 30 || strlen(buffer.phone) > 15)
		{
			cout << "Input Error" << endl;
		}
		else if (command == "insert")
		{
			insert(recs, buffer);
		}
		else if (command == "delete")
		{
			del(recs, buffer);
		}
		else if (command == "search")
		{
			int found = search(recs, buffer); // variable to store where target be found

			// check the target is found or not.
			if (found == -1) {
				cout << "Search Error" << endl;
			} else {
				cout << found << endl;
			}
		}
	}
}

//******************************************************************
//
// * print out the records.
//==================================================================
void print(vector<StRec>& recs)
//==================================================================
{
	// if records is empty, throw print error
	if (recs.empty())
	{
		cout << "Print Error" << endl;
		return;
	}

	// print out the list of students
	for (auto it = recs.begin(); it != recs.end(); it++)
	{
		cout << it->firstName << " " << it->lastName << " " << it->phone << endl;
	}
}

//******************************************************************
//
// * insert data.
//==================================================================
void insert(vector<StRec>& recs, StRec buffer)
//==================================================================
{
	int found = search(recs, buffer);

	// if the records already have 10, or the insert data already exists
	// throw insert error
	if (recs.size() == 10 || found != -1)
	{
		cout << "Insert Error" << endl;
		return;
	}

	recs.push_back(buffer);
}

//******************************************************************
//
// * delete data.
//==================================================================
void del(vector<StRec>& recs, StRec target)
//==================================================================
{
	int found = search(recs, target);

	// check is the target inside the list or not
	// if not, throw delete error
	if (found == -1)
	{
		cout << "Delete Error" << endl;
		return;
	}

	recs.erase(recs.begin() + found);
}

//******************************************************************
//
// * search data.
//==================================================================
int search(vector<StRec>& recs, StRec target)
//==================================================================
{
	for (int i = 0; i < recs.size(); i++)
	{
		if (!strcmp(target.firstName, recs[i].firstName) && !strcmp(target.lastName, recs[i].lastName) && !strcmp(target.phone, recs[i].phone))
		{
			return i;
		}
	}

	// can't find the target, throw search error
	return -1;
}