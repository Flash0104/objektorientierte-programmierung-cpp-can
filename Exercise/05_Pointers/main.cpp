#include <iostream>
#include <string>

// 2 - References
struct Teacher {
  std::string name;
  bool isBooked = false;

  // 2c: set isBooked to false
  void appointAppointment() {
    isBooked = false;
    std::cout << "Teacher " << name << " is available again." << std::endl;
  }
};

struct Student {
  std::string name;
  // 2a: field called classTeacher which is a reference
  Teacher &classTeacher;

  // 2b: print names
  void print_student_and_teacher() {
    std::cout << name << "s teacher is " << classTeacher.name << "."
              << std::endl;
  }

  // 2c: check and book
  void bookAppointment() {
    if (classTeacher.isBooked) {
      std::cout << "Teacher " << classTeacher.name << " is already booked."
                << std::endl;
    } else {
      classTeacher.isBooked = true;
      std::cout << "Booked appointment with " << classTeacher.name << "."
                << std::endl;
    }
  }
};

// 1a - Pointers vs References

void increment(int *address_to_number) { (*address_to_number)++; }

void increment(int &number) { number++; }

// 1b - Structs with Pointers
struct Element {
  int value;
  Element *next;
};

int main() {
  // 2b & 2c setup
  Teacher bob = {"Bob"};
  Student alice = {"Alice", bob};

  // 2b output
  alice.print_student_and_teacher();

  // 2c logic test
  // std::cout << alice.classTeacher.isBooked << std::endl;
  alice.bookAppointment();
  // std::cout << bob.isBooked << std::endl;

  // Test re-booking
  Student charlie = {"Charlie", bob};
  charlie.bookAppointment(); // Should fail

  // Reset
  bob.appointAppointment();

  // 1b setup
  Element first = {1, nullptr};
  Element second = {2, &first};
  // Print value from first through second's pointer
  std::cout << second.next->value << std::endl;
  std::cout << second.next->next << std::endl;

  // 1a setup
  int i = 5;
  increment(&i);
  std::cout << i << std::endl;
  increment(i);
  std::cout << i << std::endl;
  increment(&i);
  std::cout << i << std::endl;
}
