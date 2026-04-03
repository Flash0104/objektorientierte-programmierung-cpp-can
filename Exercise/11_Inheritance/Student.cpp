#include "Student.h"

Student::Student(std::string n, int sem, int matNum)
    : Person(n), semester(sem), matriculationNumber(matNum) {}

int Student::getSemester() const { return semester; }

int Student::getMatriculationNumber() const { return matriculationNumber; }

void Student::incrementSemester() { semester++; }

void Student::print() const {
  std::cout << "Name: " << getName() << ", Semester: " << semester
            << ", MatNr: " << matriculationNumber << std::endl;
}
