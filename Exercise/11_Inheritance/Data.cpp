#include "Data.h"
#include <iostream>

// a) Add student
void Data::addStudent(const Student &s) { students.push_back(s); }

// a) Remove student at index
void Data::removeStudent(size_t index) {
  if (index < students.size()) {
    students.erase(students.begin() + index);
  } else {
    std::cout << "Index out of bounds!" << std::endl;
  }
}

// a) Print all students
void Data::print() const {
  std::cout << "Data Dump:" << std::endl;
  for (const auto &s : students) {
    s.print();
  }
  std::cout << "-----------------" << std::endl;
}

// b) Increment semester for all
void Data::applyNewSemester() {
  for (auto &s : students) {
    s.incrementSemester();
  }
}

// b) Return vector of students with semester < threshold
std::vector<Student> Data::studiesLessThan(int threshold) const {
  std::vector<Student> result;
  for (const auto &s : students) {
    if (s.getSemester() < threshold) {
      result.push_back(s);
    }
  }
  return result;
}
