/*
Anastasia Yang
13 May 2024

Final Project
*/

#pragma once
#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H
#include "PersonType.h"

const int NUM_OF_CAMPUSES = 4;

class CandidateType : public PersonType {
public:
  // constructor
  CandidateType();
  CandidateType(std::string newFirst, std::string newLast, int newSSN);
  CandidateType(const CandidateType& a);
  // destructor
  ~CandidateType();

  // setters
  void updateVotesByCampus(int campusNumber, int numOfVotes);

  // getters
  int getTotalVotes() const;
  int getVotesByCampus(int campusNumber) const;

  // printing
  void printCandidateInfo() const;
  void printCandidateTotalVotes() const;
  void printCandidateCampusVotes(int campusNumber) const;

private:
  int totalVotes;
  int votesByCampus[NUM_OF_CAMPUSES];
};

#endif
