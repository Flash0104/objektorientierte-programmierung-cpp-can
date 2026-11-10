// Week 1 - Slide 24 ("bla.cpp" Example)
// Topic: Von Neumann execution, control structures, and loops
//
// In the Von Neumann architecture, programs execute instructions sequentially
// from memory, with conditional jumps (if/else) altering the instruction
// counter. This example demonstrates the Collatz (3x + 1) conjecture logic
// shown on Slide 24.

#include <iostream>

int main() {
  int x;
  std::cout << "Give me a number to start: ";
  std::cin >> x;
  std::cout << "Starting Collatz sequence with x = " << x << std::endl;

  while (x > 2) {
    if (x % 2 == 0) {
      x = x / 2;
    } else {
      x = x * 3 + 1;
    }
    std::cout << x << std::endl;
  }

  return 0;
}
