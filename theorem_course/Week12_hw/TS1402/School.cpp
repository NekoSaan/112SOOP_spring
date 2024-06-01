/************************************************************************
File:
        School.cpp
Author:
        Kuo Po Wei, powei30445@gmail.com
Create Date:
        2024/05/08
Editor:
        Kuo Po Wei, powei30445@gmail.com
Edit Date:
        2024/05/08
Description:
        Write a main program that creates three types of school
        (one from each class: School, PrivateSchool, and PublicSchool)
        and transfers students from each to another one.
************************************************************************/
#include "School.h"

// Intent: Admissions n students to the school
// Pre: amount of students to be admitted
// Post: students amount increased by n
// \param n: amount of students to be admitted
void School::admissions(int n) {
    // check if n is negative
    if (n < 0) {
        return;
    }

    students += n;
}

// Intent: Dropouts n students from the school
// Pre: amount of students to be dropped
// Post: students amount decreased by n
// \param n: amount of students to be dropped
void School::dropouts(int n) {
    // check if n is negative or n is larger than the amount of students
    if (n > students || n < 0) {
        return;
    }

    students -= n;
}

// Intent: Transfer n students from this school to target school
// Pre: amount of students to be transferred
// Post: students amount decreased by n in this school and increased by n in target school
// \param n: amount of students to be transferred
// \param target: target school to transfer students to
void School::transfer(int n, School& target) {
    // check if n is negative or n is larger than the amount of students
    if (n > students || n < 0) {
        return;
    }

    this->dropouts(n);
    target.admissions(n);
}

// Intent: Print the school information
// Pre: none
// Post: print the school information
// \param os: output stream
// \param s: school to be printed
ostream& operator<<(ostream& os, const School& s) {
    os << s.name << "\t" << s.students << "\t" << s.nextYear;

    return os;
}

// Intent: Dropouts n students from the school
// Pre: amount of students to be dropped
// Post: students amount decreased by n
// \param n: amount of students to be dropped
void PublicSchool::dropouts(int n) {
    // check if n is negative or n is larger than the amount of students
    if (n > students || n < 0) {
        return;
    }

    students -= n;

    // check if incur penalties when large amount of students(>100) leave the school at once.
    if (n > 100) {
        nextYear -= growing_rate * nextYear;
    }
}

// Intent: Apply growth to the school
// Pre: none
// Post: students amount increased by growth rate
void PublicSchool::apply_growth(void) {
    nextYear += growing_rate * nextYear;
}

// Intent: Dropouts n students from the school
// Pre: amount of students to be dropped
// Post: students amount decreased by n
// \param n: amount of students to be dropped
void PrivateSchool::dropouts(int n) {
    // check if n is negative or n is larger than the amount of students
    if (n > students || n < 0) {
        return;
    }

    students -= n;
    nextYear -= wave++ * 100;
}