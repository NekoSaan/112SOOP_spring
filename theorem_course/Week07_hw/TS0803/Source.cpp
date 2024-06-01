/************************************************************************
File:
		Source.cpp
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/03
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/04
Description:
		Please write a program to simulate the process of writing and 
		reading memory data. 
************************************************************************/
#include <iostream> // for cin & cout
#include <string> // for string format

using namespace std;

// copy data to memory
void my_memcpy(void*, const void*, size_t);

int main() {
    int total_byte, case_num;
    char* mem = nullptr;

    // read until EOF
    while (cin >> total_byte >> case_num) {
        mem = new char [total_byte] {}; // initialize memory
        string command, type; // command: Set/Get, type: String/int/short/char
        int position; // position to write or read

        // variables for different types
        string str_in;
        unsigned int int_in;
        unsigned short short_in;
        unsigned char char_in;

        // test cases start
        for (int i = 0; i < case_num; i++) {
            cin >> command >> position >> type; // read command, position, type

            // check if the position < 0?
            if (position < 0) {
                cout << "Violation Access." << endl;
                continue;
            }

            // recgonizing type
            if (type == "String") {
                // recgonizing the command
                if (command == "Set") {
                    cin.ignore();
                    getline(cin, str_in);

                    // check if the string overflows
                    if (position + str_in.size() >= total_byte) {
                        cout << "Violation Access." << endl;

                        // assign the string to the memory
                        my_memcpy((void*)(mem + position), (const void*)str_in.c_str(), (size_t)total_byte - (size_t)position);
                        continue;
                    }

                    // assign the string to the memory
                    my_memcpy((void*)(mem + position), (const void*)str_in.c_str(), str_in.size());
                }
                else if (command == "Get") {
                    char* p = mem + position;
                    int i = position;

                    // print until \0 or the end of the memory
                    while (*p != '\0' && i < total_byte) {
                        cout << (char)(*p++);
                        i++;
                    }

                    cout << endl;
                }
            }
            else if (type == "int") {
                // check if the position is out of the memory
                if (position + 4 > total_byte) {
                    cout << "Violation Access." << endl;

                    if (command == "Set") {
                        cin >> int_in;
                        // assign the int to the memory
                        my_memcpy((void*)(mem + position), (const void*)(&int_in), (size_t)total_byte - (size_t)position);
                    }

                    continue;
                }

                if (command == "Set") {
                    cin >> int_in;
                    // assign the int to the memory
                    my_memcpy((void*)(mem + position), (const void*)(&int_in), sizeof(int));
                }
                else if (command == "Get") {
                    // get the int from the memory
                    my_memcpy((void*)(&int_in), (const void*)(mem + position), sizeof(int));
                    cout << int_in << endl;
                }
            }
            else if (type == "short") {
                // check if the position is out of the memory
                if (position + 2 > total_byte) {
                    cout << "Violation Access." << endl;

                    if (command == "Set") {
                        cin >> short_in;
                        // assign the short to the memory
                        my_memcpy((void*)(mem + position), (const void*)(&short_in), (size_t)total_byte - (size_t)position);
                    }

                    continue;
                }

                if (command == "Set") {
                    cin >> short_in;
                    // assign the short to the memory
                    my_memcpy((void*)(mem + position), (const void*)(&short_in), sizeof(short));
                }
                else if (command == "Get") {
                    // get the short from the memory
                    my_memcpy((void*)(&short_in), (const void*)(mem + position), sizeof(short));
                    cout << short_in << endl;
                }
            }
            else if (type == "char") {
                int tmp;

                // check if the position is out of the memory
                if (position + 1 > total_byte) {
                    cout << "Violation Access." << endl;

                    if (command == "Set") {
                        cin >> tmp;
                        // assign the char to the memory
                        my_memcpy((void*)(mem + position), (const void*)(&char_in), (size_t)total_byte - (size_t)position);
                    }

                    continue;
                }

                if (command == "Set") {
                    cin >> tmp;
                    // assign the char to the memory
                    my_memcpy((void*)(mem + position), (const void*)(&tmp), sizeof(char));
                }
                else if (command == "Get") {
                    // get the char from the memory
                    my_memcpy((void*)(&char_in), (const void*)(mem + position), sizeof(char));
                    cout << (int)char_in << endl;
                }
            }
        }
        // release memory
        delete[] mem;
        mem = nullptr;
    }
    return 0;
}

// Intent : Copy data from src to dest
// Pre : dest is the destination memory address
// Post : Copy n bytes of data from src to dest
// \param dest : destination memory address
// \param src : source memory address
// \param n : number of bytes to copy
void my_memcpy(void* dest, const void* src, size_t n)
{
    const char* csrc = (const char*)(src);
    char* cdest = (char*)(dest);
    for (int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
}