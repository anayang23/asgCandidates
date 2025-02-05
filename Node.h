/*
Anastasia Yang
13 May 2024

Final Project
*/

#pragma once
#ifndef NODE_H
#define NODE_H
#include "CandidateType.h"

class Node {
public:
    // default constructor
    Node() : link(nullptr) {}
    // overload constructor
    Node(const CandidateType& votes, Node* theLink)
        : candidate(votes), link(theLink) {}
    // destructor
    ~Node() {}

    // getters
    Node* getLink() const { return link; }
    CandidateType getCandidate() const { return candidate; }

    // setters
    void setCandidate(const CandidateType& votes) { candidate = votes; }
    void setLink(Node* theLink) { link = theLink; }

private:
    CandidateType candidate;
    Node* link; // pointer that points to next node
};

#endif
