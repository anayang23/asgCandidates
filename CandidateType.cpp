/*
Anastasia Yang
13 May 2024

Final Project
*/

#include "CandidateList.h"
#include "Node.h"
#include <iostream>
using namespace std;

// default constructor
CandidateList::CandidateList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

// overload constructor
CandidateList::CandidateList(Node* firstNode, Node* lastNode, int newCount) {
    first = firstNode;
    last = lastNode;
    count = newCount;
}

// copy constructor
CandidateList::CandidateList(const CandidateList& other) {
    destroyList();
    first = other.first;
    last = other.last;
    count = other.count;
}

// destructor
CandidateList::~CandidateList() { destroyList(); }
// setters
void CandidateList::addCandidate(CandidateType newCandidate) {
    Node* newNode = new Node(newCandidate, nullptr);
    if (newNode) {
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            last->setLink(newNode);
            last = newNode;
        }
        count++;
    }
}

// getters / printers
int CandidateList::getWinner() const {
    Node* current = first;
    int mostVotes = 0;
    int mostVotesSSN = 0;
    while (current != nullptr) {
        if (current->getCandidate().getTotalVotes() > mostVotes) {
            mostVotes = current->getCandidate().getTotalVotes();
            mostVotesSSN = current->getCandidate().getSSN();
        }
        current = current->getLink();
    }
    return mostVotesSSN;
}

bool CandidateList::searchCandidate(int SSN) const {
    Node* current = first;
    while (current != nullptr) {
        if (current->getCandidate().getSSN() == SSN) {
            return true;
        }
        current = current->getLink();
    }
    return false;
}

void CandidateList::printCandidateName(int SSN) const {
    Node* current = first;
    if (first == nullptr) {
        cout << "=> List is empty\n";
    }
    else if (!searchCandidate(SSN)) {
        cout << "=> SSN not in list\n";
    }
    else {
        while (current->getCandidate().getSSN() != SSN) {
            current = current->getLink();
        }
        current->getCandidate().printName();
        cout << endl;
    }
}

void CandidateList::printAllCandidates() const {
    Node* current = first;
    while (current != nullptr) {
        current->getCandidate().printCandidateInfo();
        cout << endl;
        current = current->getLink();
    }
}

void CandidateList::printCandidateCampusVotes(int SSN, int divisionNum) const {
    Node* current = first;
    if (first == nullptr) {
        cout << "=> List is empty\n";
    }
    else if (!searchCandidate(SSN)) {
        cout << "=> SSN not in list\n";
    }
    else {
        while (current->getCandidate().getSSN() != SSN) {
            current = current->getLink();
        }
        current->getCandidate().printCandidateCampusVotes(divisionNum);
        cout << endl;
    }
}

void CandidateList::printCandidateTotalVotes(int SSN) const {
    Node* current = first;
    if (first == nullptr) {
        cout << "=> List is empty\n";
    }
    else if (!searchCandidate(SSN)) {
        cout << "=> SSN not in list\n";
    }
    else {
        while (current->getCandidate().getSSN() != SSN) {
            current = current->getLink();
        }
        current->getCandidate().printCandidateTotalVotes();
        cout << endl;
    }
}

void CandidateList::printFinalResults() {
    int winnerSSN = getWinner();
    cout << "The winner is...\n";
    printCandidateName(winnerSSN);
    cout << endl;
}

void CandidateList::destroyList() {
    Node* current = first;
    while (current != nullptr) {
        first = first->getLink();
        delete current;
        current = first;
    }
    first = nullptr;
    last = nullptr;
}
