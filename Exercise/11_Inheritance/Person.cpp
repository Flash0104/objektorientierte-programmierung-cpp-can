#include "Person.h"

Person::Person(std::string n) : name(n) {}

std::string Person::getName() const { return name; }
