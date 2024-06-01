/************************************************************************
File:
		main.cpp
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
#include "Database.h"

int main(void) {
    LibraryDatabase db;
    string line;

    // read input from cin until EOF
    while (getline(cin, line)) {
        istringstream iss(line); // create stringstream
        string command;
        iss >> command;

        // operate according to the command
        if (command == "Insert") {
            string title, author;
            int edition;

            // read title, author and edition from stringstream
            if (iss >> quoted(title) >> quoted(author) >> edition) {
                db.insert(title, author, edition);
            }
            else {
                cout << "Incomplete Command.\n";
            }
        }
        else if (command == "Delete") {
            string subCommand;
            iss >> subCommand;

            // operate according to the subcommand
            if (subCommand == "Edition") {
                string title, author;
                int edition;

                // read title, author and edition from stringstream
                if (iss >> quoted(title) >> quoted(author) >> edition) {
                    db.deleteEdition(title, author, edition);
                }
                else {
                    cout << "Incomplete Command.\n";
                }
            }
            else if (subCommand == "Book") {
                string title, author;

                // read title and author from stringstream
                if (iss >> quoted(title) >> quoted(author)) {
                    db.deleteBook(title, author);
                }
                else {
                    cout << "Incomplete Command.\n";
                }
            }
            else {
                cout << "Unknown Command.\n";
            }
        }
        else if (command == "Find") {
            string subCommand;
            iss >> subCommand;

            // operate according to the subcommand
            if (subCommand == "Book") {
                string title, author;
                
                // read title and author from stringstream
                if (iss >> quoted(title) >> quoted(author)) {
                    db.findBook(title, author);
                }
                else {
                    cout << "Incomplete Command.\n";
                }
            }
            else if (subCommand == "Author") {
                string author;

                // read author from stringstream
                if (iss >> quoted(author)) {
                    db.findAuthor(author);
                }
                else {
                    cout << "Incomplete Command.\n";
                }
            }
            else {
                cout << "Unknown Command.\n";
            }
        }
        else if (command == "Sort") {
            string subCommand;
            
            // read subcommand from stringstream
            if (iss >> subCommand >> subCommand);
            else {
                cout << "Incomplete Command.\n";
                continue;
            }

            // operate according to the subcommand
            if (subCommand == "Title") {
                db.sortByTitle();
            }
            else if (subCommand == "Author") {
                db.sortByAuthor();
            }
            else {
                cout << "Unknown Command.\n";
            }
        }
        else {
            cout << "Unknown Command.\n";
        }
    }
    return 0;
}
