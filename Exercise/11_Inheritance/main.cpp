#include "Data.h"
#include "Student.h"
#include <iostream>

int main() {
  std::cout << "--- Exercise 1: Person & Student ---" << std::endl;
  Student s1("Alice", 1, 1001);
  Student s2("Bob", 3, 1002);
  Student s3("Charlie", 5, 1003);

  s1.print();
  std::cout << "Incrementing Alice's semester..." << std::endl;
  s1.incrementSemester();
  s1.print();

  std::cout << "\n--- Exercise 2: Data & Vector ---" << std::endl;
  Data uniData;
  uniData.addStudent(s1); // Alice is now Sem 2
  uniData.addStudent(s2); // Bob is Sem 3
  uniData.addStudent(s3); // Charlie is Sem 5

  uniData.print();

  std::cout << "Applying new semester to all..." << std::endl;
  uniData.applyNewSemester();
  uniData.print();
  // Alice: 3, Bob: 4, Charlie: 6

  std::cout << "Students with semester < 5:" << std::endl;
  auto juniors = uniData.studiesLessThan(5);
  for (const auto &s : juniors) {
    s.print();
  }
  // Should print Alice (3) and Bob (4)

  std::cout << "\nRemoving student at index 1 (Bob)..." << std::endl;
  uniData.removeStudent(1);
  uniData.print();

  return 0;
}
