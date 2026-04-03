#ifndef DATA_H
#define DATA_H

#include "Student.h"
#include <vector>

class Data {
private:
  std::vector<Student> students;

public:
  // a) Add student
  void addStudent(const Student &s);

  // a) Remove student at index
  void removeStudent(size_t index);

  // a) Print all students
  void print() const;

  // b) Increment semester for all
  void applyNewSemester();

  // b) Return vector of students with semester < threshold
  std::vector<Student> studiesLessThan(int threshold) const;
};

#endif // DATA_H
