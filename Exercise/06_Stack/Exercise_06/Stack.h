//
// Created by Thies Josten on 12.11.24.
//

#ifndef EXERCISE_06_STACK_H
#define EXERCISE_06_STACK_H

class Stack {

private:
  struct Element {
    int value;
    Element *next;
  };
  Element *head{nullptr};
  int length{0};

public:
  Stack() = default;
  Stack(const Stack &) = delete;
  Stack &operator=(const Stack &) = delete;
  Stack(Stack &&other) noexcept;
  Stack &operator=(Stack &&other) noexcept;

  // Exercise 1 a) Write the method void push(int value)
  void push(int value);
  
  // Exercise 1 b) Complete the method void pop()
  void pop();
  
  // Exercise 1 c) Write the method int size() returning the length of the stack.
  int size();
  
  // Exercise 2 a) Write the method void print() iterating over the entire Stack
  void print();
  
  // Exercise 2 c) Finally write the deconstructor: ~Stack()
  ~Stack();
};

#endif // EXERCISE_06_STACK_H
