#include "Exercise1_Arrays/Arrays.cpp"
#include "Exercise1_Arrays/Arrays.h"
#include "Exercise2_Structs/Structs.cpp"
#include "Exercise2_Structs/Structs.h"
#include <iostream>

int main() {
  // =========================================================================
  // Problem 3.1: Arrays
  // =========================================================================
  std::cout << "=== Problem 3.1: Arrays ===" << std::endl;

  double grades[] = {1.0, 2.3, 2.3, 3.0, 3.7, 4.0};
  int amount_of_grades = 6;

  // a) Average calculation
  std::cout << "Average grade: " << average(grades, amount_of_grades)
            << std::endl;

  // b) i) Compare test
  std::cout << "compare(5.0, 4.9): " << (compare(5.0, 4.9) ? "true" : "false")
            << std::endl;
  std::cout << "compare(2.3, 2.300001): "
            << (compare(2.3, 2.300001) ? "true" : "false") << std::endl;

  // b) ii) & d) Linear search vs Binary search
  std::cout << "contains(2.3) index: "
            << contains(grades, amount_of_grades, 2.3) << std::endl;
  std::cout << "contains(1.7) index: "
            << contains(grades, amount_of_grades, 1.7) << std::endl;
  std::cout << "contains_binary_search(2.3) index: "
            << contains_binary_search(grades, amount_of_grades, 2.3)
            << std::endl;
  std::cout << "contains_binary_search(1.7) index: "
            << contains_binary_search(grades, amount_of_grades, 1.7)
            << std::endl;

  std::cout << std::endl;

  // =========================================================================
  // Problem 3.2: Structs (Pizza)
  // =========================================================================
  std::cout << "=== Problem 3.2: Structs (Pizza) ===" << std::endl;

  // a) Instantiate two Pizza objects
  Pizza pizza1 = {28.0f, 7.5f};
  Pizza pizza2 = {29.0f, 8.0f};

  // b) & c) Test both methods in main()
  std::cout << "Pizza 1 (" << pizza1.diameter << " cm, " << pizza1.price
            << " EUR):" << std::endl;
  std::cout << "  - Price per cm^2: " << pizza1.price_per_cm2() << " EUR/cm^2"
            << std::endl;
  std::cout << "  - Area for 5.00 EUR: " << pizza1.five_euro_get_you_x_cm2()
            << " cm^2" << std::endl;

  std::cout << "Pizza 2 (" << pizza2.diameter << " cm, " << pizza2.price
            << " EUR):" << std::endl;
  std::cout << "  - Price per cm^2: " << pizza2.price_per_cm2() << " EUR/cm^2"
            << std::endl;
  std::cout << "  - Area for 5.00 EUR: " << pizza2.five_euro_get_you_x_cm2()
            << " cm^2" << std::endl;

  if (pizza1.five_euro_get_you_x_cm2() > pizza2.five_euro_get_you_x_cm2()) {
    std::cout << "=> Pizza 1 offers the best value for money!" << std::endl;
  } else if (pizza2.five_euro_get_you_x_cm2() >
             pizza1.five_euro_get_you_x_cm2()) {
    std::cout << "=> Pizza 2 offers the best value for money!" << std::endl;
  } else {
    std::cout << "=> Both pizzas offer the exact same value for money!"
              << std::endl;
  }

  return 0;
}
