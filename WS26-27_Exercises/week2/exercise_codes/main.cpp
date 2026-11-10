#include <iostream>
bool nth_bit_is_zero(int, int);
void print_int_as_binary(int);

int main() {
  std::cout << "Hello, World!" << std::endl;

  print_int_as_binary(-8);
  print_int_as_binary(8);
  print_int_as_binary(0);
  return 0;
}

bool nth_bit_is_zero(int number, int n) {
  // Move the 1 to bit position n. temp has only this bit set to 1.
  int temp = 1 << n;

  // Check whether the same bit in number is 1.
  // This returns true for a 1 bit and false for a 0 bit.
  return (number & temp) != 0;
}

void print_int_as_binary(int number) {
  int number_of_bits = sizeof(int) * 8;

  for (int bit = number_of_bits - 1; bit >= 0; bit--) {
    if (nth_bit_is_zero(number, bit)) {
      std::cout << "1";
    } else {
      std::cout << "0";
    }
  }

  std::cout << std::endl;
}
