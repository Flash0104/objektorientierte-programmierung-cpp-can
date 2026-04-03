#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
  // a) Name cannot be changed after creation (via public interface)
  // Removed const to allow vector assignment/erasure
  std::string name;

public:
  Person(std::string n);

  // Return the name
  std::string getName() const;
};

#endif // PERSON_H
