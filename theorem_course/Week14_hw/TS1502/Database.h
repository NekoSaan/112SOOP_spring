/************************************************************************
File:
		Database.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/05/21
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/05/21
Description:
		Please implement a library database system to store some information
		of books, including the title, the author, and the editions of book.
		You will also need to implement the following commands to manage the database.
************************************************************************/
#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <iostream>		// for cin & cout
#include <algorithm>	// for some standard library functions
#include <set>          // for set format
#include <map>			// for map format
#include <vector>		// for vector format
#include <string>		// for string format
#include <sstream>      // for ss
#include <iomanip>      // for quoted function
using namespace std;

// structure of book
struct Book {
    string title;
    string author;
    int edition;

    // operator overloading <
    bool operator<(const Book& other) const {
        return tie(title, author, edition) < tie(other.title, other.author, other.edition);
    }
};

// Library database class
class LibraryDatabase {
private:
    set<Book> books;

public:
    // insert book
    void insert(const string& title, const string& author, int edition) {
        Book book{ title, author, edition }; // create new book
        auto result = books.insert(book); // insert book into set, and set check flag

        // check if the book is already exist or not?
        if (result.second) {
            // if not, insert the book
            cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
        }
        else {
            cout << "Datum already exist.\n";
        }
    }

    // delete edition by title, author and edition
    void deleteEdition(const string& title, const string& author, int edition) {
        Book book{ title, author, edition }; // create new book
        auto it = books.find(book); // find book in set

        // check if the book is exist or not?
        if (it != books.end()) {
            books.erase(it); // if yes, erase the book
            cout << "Delete " << author << "'s " << title << ", Edition: " << edition << ".\n";
        }
        else {
            cout << "Datum doesn't exist.\n";
        }
    }

    // delete book by title and author
    void deleteBook(const string& title, const string& author) {
        auto it = books.begin(); // set iterator to the beginning
        bool found = false; // flag for checking if the book is found or not

        // find the book in set with all editions
        while (it != books.end()) {
            // if found, erase the book
            if (it->title == title && it->author == author) {
                it = books.erase(it);
                found = true;
            }
            else {
                ++it;
            }
        }

        // print message according to the result
        if (!found) {
            cout << "Book doesn't exist.\n";
        }
        else {
            cout << "Delete " << author << "'s " << title << ".\n";
        }
    }

    // find book by title and author
    void findBook(const string& title, const string& author) const {
        vector<int> editions;

        // find all editions of the book
        for (const auto& book : books) {
            if (book.title == title && book.author == author) {
                editions.push_back(book.edition);
            }
        }

        // print message according to the result
        if (!editions.empty()) {
            sort(editions.begin(), editions.end()); // sort editions
            cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";

            // print all editions
            for (int i = 0; i < editions.size(); i++) {
                cout << editions[i];

                if (i != editions.size() - 1) {
                    cout << ", ";
                }
            }

            cout << endl;
        }
        else {
            cout << "Book doesn't exist.\n";
        }
    }

    // find author by author
    void findAuthor(const string& author) const {
        set<string> titles;

        // find all books of the author
        for (const auto& book : books) {
            // if found, insert the title into set
            if (book.author == author) {
                titles.insert(book.title);
            }
        }

        // print message according to the result
        if (!titles.empty()) {
            cout << author << "'s Books: ";
            size_t index = 0;

            // print all titles
            for (const auto& title : titles) {
                cout << title;

                if (index++ != titles.size() - 1) {
                    cout << ", ";
                }
            }

            cout << "\n";
        }
        else {
            cout << "No book found.\n";
        }
    }

    // sort by title
    void sortByTitle() const {
        std::map<std::pair<std::string, std::string>, std::vector<int>> titleMap;

        // insert all books into map
        for (const auto& book : books) {
            titleMap[{book.title, book.author}].push_back(book.edition);
        }

        // print all books after sorting
        for (auto& entry : titleMap) {
            std::sort(entry.second.begin(), entry.second.end());
            std::cout << "Title: " << entry.first.first << "\tAuthor: " << entry.first.second << "\tEdition: ";

            // print all editions
            for (size_t i = 0; i < entry.second.size(); ++i) {
                std::cout << entry.second[i];

                if (i < entry.second.size() - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << "\n";
        }
    }

    // sort by author
    void sortByAuthor() const {
        std::map<std::pair<std::string, std::string>, std::vector<int>> authorMap;

        // insert all books into map
        for (const auto& book : books) {
            authorMap[{book.author, book.title}].push_back(book.edition);
        }

        // print all books after sorting
        for (auto& entry : authorMap) {
            std::sort(entry.second.begin(), entry.second.end());
            std::cout << "Title: " << entry.first.second << "\tAuthor: " << entry.first.first << "\tEdition: ";

            // print all editions
            for (size_t i = 0; i < entry.second.size(); ++i) {
                std::cout << entry.second[i];
                if (i < entry.second.size() - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << "\n";
        }
    }
};

#endif // _DATABASE_H_
