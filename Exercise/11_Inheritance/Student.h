#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

// b) Student inherits from Person
class Student : public Person {
private:
  int semester;
  // Matriculation number given on creation, not changeable
  // Removed const to allow vector assignment/erasure
  int matriculationNumber;

public:
  Student(std::string n, int sem, int matNum);

  int getSemester() const;
  int getMatriculationNumber() const;

  // c) Increment semester
  void incrementSemester();

  // c) Print values
  void print() const;
};

#endif // STUDENT_H
