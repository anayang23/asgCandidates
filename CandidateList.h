/*
Anastasia Yang
13 May 2024

Final Project
*/

#pragma once
#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H
#include "Node.h"

class CandidateList {
public:
  // default constructors
  CandidateList();
  // overload constructors
  CandidateList(Node* firstNode, Node* lastNode, int newCount);
  // copy constructor
  CandidateList(const CandidateList& other);

  // destructor
  ~CandidateList();

  // setters
  void addCandidate(CandidateType newCandidate);

  // getters / printers
  int getWinner() const;
  bool searchCandidate(int SSN) const;

  // printing functions
  void printCandidateName(int SSN) const;
  void printAllCandidates() const;
  void printCandidateCampusVotes(int SSN, int divisionNum) const;
  void printCandidateTotalVotes(int SSN) const;
  void printFinalResults();
  void destroyList();

private:
  // member variables
  Node* first;
  Node* last;
  int count;
};

#endif
