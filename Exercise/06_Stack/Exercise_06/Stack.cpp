//
// Created by Thies Josten on 12.11.24.
//

#include "Stack.h"
#include <iostream>

// Exercise 1 a) Write the method void push(int value), which creates a new Element holding the given value.
// That Element is then pushed to the beginning of the stack. i.E. head points to the new Element
// and the next pointer of the new Element points to where the head was previously pointing to.
// Remember to also change the length of your stack.
void Stack::push(int value) {
  Element *newElement = new Element{value, head};
  head = newElement;
  length++;
}

// Exercise 1 b) Complete the method void pop() you can find in Stack.cpp. 
// The method should properly remove the current head Element from the Stack. 
// Therefore the previously second Element of the Stack shall now be stored in head. 
// Remember to also change the length of your stack.
void Stack::pop() {
  if (head == nullptr) {
    return;
  }
  Element *temp = head;
  head = head->next;
  delete temp; // Hint: delete <object-pointer> will free the object from the heap.
  length--;
}

// Exercise 1 c) Write the method int size() returning the length of the stack.
int Stack::size() { return length; }

// Exercise 2 a) Write the method void print() iterating over the entire Stack and printing each value stored.
// Format your output as seen below: Output: [1,2,3]
void Stack::print() {
  std::cout << "[";
  Element *current = head;
  while (current != nullptr) {
    std::cout << current->value;
    if (current->next != nullptr) {
      std::cout << ",";
    }
    current = current->next;
  }
  std::cout << "]" << std::endl;
}

// Exercise 2 c) Finally write the deconstructor: ~Stack() using the delete <object-pointer> again. 
// The method shall iterate over the Stack freeing all Elements from the heap.
Stack::~Stack() {
  // You might want to print a message inside of the deconstructor, so you can see when it is automatically invoked when running your code.
  std::cout << "Destructor called" << std::endl;
  
  Element *current = head;
  while (current != nullptr) {
    Element *nextElement = current->next;
    delete current; // Iterate over the Stack freeing all Elements from the heap (delete <object-pointer> again).
    current = nextElement;
  }
  head = nullptr;
  length = 0;
}

Stack::Stack(Stack &&other) noexcept : head(other.head), length(other.length) {
  other.head = nullptr;
  other.length = 0;
}

Stack &Stack::operator=(Stack &&other) noexcept {
  if (this != &other) {
    // Free existing resources
    while (head != nullptr) {
      pop();
    }

    // Steal resources
    head = other.head;
    length = other.length;

    // Reset source
    other.head = nullptr;
    other.length = 0;
  }
  return *this;
}
