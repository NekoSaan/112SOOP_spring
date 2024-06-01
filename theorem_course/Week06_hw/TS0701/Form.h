/************************************************************************
File:
		Form.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/03/26
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/03/26
Description:
		Here is the rule of a word game: Give the player a word and the
		player should use the letters in the given word to compose new
		words. For example, with the given word "swimming", you can get
		words like "wing", "sing" and "miming".
************************************************************************/
#ifndef FORM_H
#define FORM_H
#include <iostream> // for cin & cout
#include <string> // for string format
#include <vector> // for vector structure
#include <unordered_map> // for unordered_map structure
#include <fstream> // for file I/O operation
using namespace std;

//=======================================================================
//
// * Form Class
//=======================================================================
class Form {
private:
	size_t len; // store the given input word's length
	string fileName; // store the open file's name
	string inputWord; // store the given input word
	unordered_map<char, int> map; // store the frequency of each chars in inputWord
	vector<string> ans; // store all fitted answer
public:
	// set input
	void SetInputWord(string inputWord)
	{
		this->inputWord = inputWord;
	}

	// process input
	void ProcessInputWord()
	{
		// record each chars' appear frequency
		for (char& c : this->inputWord)
		{
			this->map[tolower(c)]++;
		}

		// record length of input word
		this->len = inputWord.length();
	}

	// set file name
	void SetFileName(string fileName)
	{
		this->fileName = fileName;
	}

	// read-in data and compare
	void Load_CompareWord()
	{
		// file input
		ifstream f(this->fileName, ios::in);

		string tmp; // variable to store word

		// read until EOF
		while (f >> tmp)
		{
			// if the compare word's length > given word
			// it's impossiple to create it by given word's chars.
			if (tmp.length() > this->len) continue;

			// each word need a valid data, copy from origin
			unordered_map<char, int> freq = this->map;
			bool flag = true; // flag to detect is the word valid or not

			// check if the word can be created by given word's chars.
			for (char& c : tmp)
			{
				if (--freq[c] < 0)
				{
					flag = false;
					break;
				}
			}

			// record valid answers
			if (flag) this->ans.push_back(tmp);
		}

		f.close();
	}

	// print answers
	void PrintFoundWords()
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << endl;
		}
	}
};

#endif