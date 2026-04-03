#include <iostream>
#include <memory>

#include <vector>

// Exercise 2b: Function to print vector
void printVector(std::vector<int> my_vector) {
  std::cout << "Vector: ";
  for (size_t i = 0; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << (i < my_vector.size() - 1 ? ", " : "");
  }
  std::cout << std::endl;
}

int main() {
  // --- Exercise 1: Shared Pointers ---
  std::cout << "--- Exercise 1: Shared Pointers ---" << std::endl;

  // a) Define int x = 42 (conceptually) and shared_ptr pointing to it using
  // make_unique Note: We create a shared_ptr by moving a unique_ptr into it.
  std::shared_ptr<int> p1 = std::make_unique<int>(42);

  // Create second pointer equal to the first
  std::shared_ptr<int> p2 = p1;

  std::cout << "p1 use_count(): " << p1.use_count() << std::endl;
  // Explanation: Should be 2 because p1 and p2 share ownership.

  // b) Make second pointer nullptr
  std::cout << "\nSetting p2 to nullptr..." << std::endl;
  p2 = nullptr;

  std::cout << "p1 use_count(): " << p1.use_count() << std::endl;
  std::cout << "p2 use_count(): " << p2.use_count() << std::endl;
  // Explanation:
  // p1 use_count is 1 because p2 no longer shares ownership.
  // p2 use_count is 0 because it points to nothing.

  // c) Address of pointer vs get()
  std::cout << "\nAddress of p1 (&p1): " << &p1 << std::endl;
  std::cout << "Value of p1.get():   " << p1.get() << std::endl;
  // Explanation:
  // &p1 is the address of the shared_ptr object itself on the stack.
  // p1.get() is the address of the integer (42) allocated on the heap.
  // Wrapper class concept: The smart pointer is a small object on the stack
  // managing a resource on the heap.

  // --- Exercise 2: Vectors ---
  std::cout << "\n--- Exercise 2: Vectors ---" << std::endl;

  // a) Vector with values 0 to 9
  std::vector<int> myVector;
  for (int i = 0; i < 10; ++i) {
    myVector.push_back(i);
  }
  std::cout << "Initial ";
  printVector(myVector);

  // Erase the 5th Element (Index 4, value 4)
  // iterator to 5th element is begin() + 4
  if (myVector.size() >= 5) {
    myVector.erase(myVector.begin() + 4);
  }
  std::cout << "After erasing 5th element ";
  printVector(myVector);

  // Delete the first five Elements
  // Range erase: [begin, begin + 5)
  if (myVector.size() >= 5) {
    myVector.erase(myVector.begin(), myVector.begin() + 5);
  }
  std::cout << "After erasing first 5 elements ";
  printVector(myVector);

  return 0;
}
