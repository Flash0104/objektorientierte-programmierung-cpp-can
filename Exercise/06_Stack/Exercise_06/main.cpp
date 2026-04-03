#include "Stack.h"
#include <iostream>

// One possible solution, shall be kept
bool isPrime(int number) {
  if (number < 2)
    return false;
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}

// Exercise 2 b) In main.cpp write a function Stack primeStack(int upper_bound) 
// returning a Stack filled with all prime numbers less than the upper_bound.
Stack primeStack(int upper_bound) {
  Stack primes;
  // Let's iterate forwards to push ascending primes 
  // You can use your isPrime function from previous exercises or our implementation provided in main.cpp.
  for (int i = 2; i < upper_bound; ++i) {
    if (isPrime(i)) {
      primes.push(i);
    }
  }
  return primes;
}

// "Try out your code as usual in main.cpp."
int main() {
  std::cout << "--- Exercise 2a Test ---" << std::endl;
  
  // Format your output as seen below
  Stack my_Stack;
  my_Stack.push(3);
  my_Stack.push(2);
  my_Stack.push(1);
  my_Stack.print(); // Output: [1,2,3]

  std::cout << "\n--- Exercise 2b Test (Prime Stack) ---" << std::endl;
  // Test code for Prime stack, with elements less than 20
  Stack pStack = primeStack(20);
  pStack.print(); 

  std::cout << "\n--- End of Main (Destructors will run) ---" << std::endl;
  return 0;
}
