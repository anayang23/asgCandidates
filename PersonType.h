/*
Anastasia Yang
13 May 2024

Final Project
*/

// abstract class
#pragma once
#ifndef PERSONTYPE_H
#define PERSONTYPE_H
#include <string>

class PersonType {
public:
    // default constructors
    PersonType();
    // overload constructors
    PersonType(std::string fName, std::string lName, int SSN);
    // copy constructor
    PersonType(const PersonType& x);

    // destructor
    ~PersonType();

    // re-sets person info
    void setPersonInfo(std::string newFirst, std::string newLast, int newSSN);

    // getters
    std::string getFirstName() const;
    std::string getLastName() const;
    int getSSN() const;

    // printing functions
    void printName() const;
    void printPersonInfo() const;
    void printSSN() const;

private:
    // member variables
    std::string fName;
    std::string lName;
    int SSN;
};

#endif
