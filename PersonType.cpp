/*
Anastasia Yang
13 May 2024

Final Project
*/

#include "PersonType.h"
#include <iostream>
#include <string>
using namespace std;

// default constructors
PersonType::PersonType() {
    SSN = 0;
}

// overload constructors
PersonType::PersonType(string newFirst, string newLast, int newSSN) {
    fName = newFirst;
    lName = newLast;
    SSN = newSSN;
}

// copy constructor
PersonType::PersonType(const PersonType& x) {
    fName = x.fName;
    lName = x.lName;
    SSN = x.SSN;
}

// destructor
PersonType::~PersonType() {}

// re-sets person info
void PersonType::setPersonInfo(string newFirst, string newLast, int newSSN) {
    fName = newFirst;
    lName = newLast;
    SSN = newSSN;
}

// getters
string PersonType::getFirstName() const { return fName; }

string PersonType::getLastName() const { return lName; }

int PersonType::getSSN() const { return SSN; }

// printing functions
void PersonType::printName() const { cout << lName << ", " << fName; }

void PersonType::printSSN() const {
    int ssn = SSN;
    cout << (ssn / 1000000) << "-" << ((ssn / 10000) % 100) << "-" << (ssn % 10000);
}

void PersonType::printPersonInfo() const {
    printSSN();
    cout << " " << fName << " " << lName;
}
