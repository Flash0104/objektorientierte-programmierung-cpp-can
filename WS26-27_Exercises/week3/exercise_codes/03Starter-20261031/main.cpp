#include "Exercise1_Arrays/Arrays.h"
#include "Exercise2_Structs/Structs.h"
#include <iostream>

int main() {
  // Needed for Arrays
  double grades[]{1.0, 2.3, 2.3, 3.0, 3.7, 4.0};
  int amount_of_grades = 6;
  // std::cout << average(grades, amount_of_grades) << std::endl;
  // std::cout << contains_binary_search(grades, amount_of_grades, 2.3);

  Pizza pizza1 = {28, 7.5};
  Pizza pizza2 = {29, 8};
  std::cout << pizza1.five_euro_get_you_x_cm2() << std::endl
            << pizza2.five_euro_get_you_x_cm2();
  return 0;
}
