#ifndef INC_04_EXERCISE_STRUCTS_CPP
#define INC_04_EXERCISE_STRUCTS_CPP

#include "Structs.h"

// Problem 3.2 b) Calculate price per square centimeter (EUR / cm^2)
float Pizza::price_per_cm2() {
  float radius = diameter / 2.0f;
  float area = radius * radius * 3.14159f;
  return price / area;
}

// Problem 3.2 c) Calculate total area (in cm^2) obtainable for 5.00 Euros
float Pizza::five_euro_get_you_x_cm2() { return 5.0f / price_per_cm2(); }

#endif // INC_04_EXERCISE_STRUCTS_CPP
