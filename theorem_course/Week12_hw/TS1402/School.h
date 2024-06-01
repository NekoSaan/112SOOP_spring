/************************************************************************
File:
        School.h
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
#ifndef _SCHOOL_H_
#define _SCHOOL_H_
#include <iostream>
#include <string>

using namespace std;

// School Class
class School {
protected:
    string name;
    int students;
    int nextYear;

public:
    // Default constructor
    School(string name, int num) : name(name), students(num), nextYear(num) {};

    // admission
    void admissions(int);

    // dropout from school
    virtual void dropouts(int);

    // transfer from school to school
    void transfer(int, School&);

    // Overload the << operator
    friend ostream& operator<<(ostream&, const School&);
};

// Public school class, inherti School
class PublicSchool : public School {
private:
    double growing_rate;

public:
    // Default Constructor
    PublicSchool(string name, int num) : School::School(name, num), growing_rate(0.05) {};

    // dropouts function overwrite
    void dropouts(int) override;

    // apply growth
    void apply_growth(void);
};

// Private school class, inherti school
class PrivateSchool : public School {
private:
    int wave;

public:
    // Default Constructor
    PrivateSchool(string name, int num) : School::School(name, num), wave(0) {};

    // dropouts function overwrite
    void dropouts(int) override;
};

#endif // _SCHOOL_H_