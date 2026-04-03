#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
#include <memory>

int main() {
  // --- Exercise 1: Your very own classes ---
  std::cout << "--- Exercise 1 ---" << std::endl;

  // Rectangle test
  Rectangle rect(5.0, 3.0);
  std::cout << "Rectangle (Width: " << rect.getWidth()
            << ", Height: " << rect.getHeight() << ")" << std::endl;
  std::cout << "Rectangle Area: " << rect.calculate_area() << std::endl;

  // Modify Rectangle
  rect.setWidth(10.0);
  std::cout << "New Rectangle Width: " << rect.getWidth() << std::endl;
  std::cout << "New Rectangle Area: " << rect.calculate_area() << std::endl;

  std::cout << std::endl;

  // Circle test
  Circle circ(4.0);
  std::cout << "Circle (Radius: " << circ.getRadius() << ")" << std::endl;
  std::cout << "Circle Area: " << circ.calculate_area() << std::endl;

  // --- Exercise 2: Smart pointers ---
  std::cout << "\n--- Exercise 2 ---" << std::endl;

  // a) Declare unique_ptr
  std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
  std::unique_ptr<int> ptr2;

  std::cout << "Created ptr1 with value 42." << std::endl;

  // ptr2 = ptr1;
  // ERROR EXPLANATION:
  // The line 'ptr2 = ptr1;' causes a compile-time error.
  // std::unique_ptr is designed to have exclusive ownership of the object it
  // points to. Its copy constructor and copy assignment operator are deleted to
  // prevent multiple pointers from managing the same resource, which would lead
  // to double-free errors.
  std::cout << "Attempting 'ptr2 = ptr1' fails to compile because unique_ptr "
               "cannot be copied (ownership is unique)."
            << std::endl;

  // b) Use std::move
  std::cout << "ptr1 before move: " << (ptr1 ? "valid" : "nullptr")
            << std::endl;

  ptr2 = std::move(ptr1);

  std::cout << "Moved ptr1 to ptr2 using std::move(ptr1)." << std::endl;
  std::cout << "ptr1 after move: " << (ptr1 ? "valid" : "nullptr") << std::endl;
  std::cout << "ptr2 after move: " << (ptr2 ? "valid" : "nullptr") << std::endl;

  if (ptr2) {
    std::cout << "Value inside ptr2: " << *ptr2 << std::endl;
  }

  return 0;
}
