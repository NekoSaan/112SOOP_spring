/************************************************************************
File:
        Template.h
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/05/14
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/05/14
Description:
        Please implement Binary Search using template, and provide both
        iterative and recursive versions.
************************************************************************/
#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_
#include <iostream>

using namespace std;

// Intent: Perform binary search on an array of type T
// Pre: a is an array of type T, first and last are the first and last 
// indices of the array, key is the value to search for.
// Post: found is true if key is found in the array, false otherwise.
// \param a[]: an array of type T
// \param first: the first index of the array
// \param last: the last index of the array
// \param key: the value to search for
// \param found: true if key is found in the array, false otherwise
// \param location: the index of the key in the array
template<typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    do {
        int mid = (first + last) / 2;

        // key found, set location index and found flag
        if (a[mid] == key) {
            location = mid;
            found = true;
            return;
        }

        // change the search range based on the value of key
        if (key > a[mid]) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
        // iterate till key is found or first is greater than last
    } while (first <= last); 

    found = false;
}

// Intent: Perform binary search on an array of type T
// Pre: a is an array of type T, first and last are the first and last
// indices of the array, key is the value to search for.
// Post: found is true if key is found in the array, false otherwise.
// \param a[]: an array of type T
// \param first: the first index of the array
// \param last: the last index of the array
// \param key: the value to search for
// \param found: true if key is found in the array, false otherwise
// \param location: the index of the key in the array
template<typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    // if first index is greater than last index, means key is not found
    if (first > last) {
        found = false;
        return;
    }

    int mid = (first + last) / 2;

    // key found, set location index and found flag
    if (a[mid] == key) {
        location = mid;
        found = true;
        return;
    }

    // change the search range based on the value of key
    if (key > a[mid]) {
        RecBinarySearch(a, mid + 1, last, key, found, location);
    }
    else {
        RecBinarySearch(a, first, mid - 1, key, found, location);
    }
}

#endif // _TEMPLATE_H_
