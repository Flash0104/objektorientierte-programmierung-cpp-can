#include <cmath>
#include <iostream>

// =============================================================================
// Problem 4.1: Computing with complex numbers
// =============================================================================
struct Complex {
  double real; // Real part (Cartesian)
  double imag; // Imaginary part (Cartesian)
  double r;    // Magnitude (Polar)
  double phi;  // Phase angle in radians (Polar)

  // Default constructor (0 + i*0)
  Complex() : real(0.0), imag(0.0), r(0.0), phi(0.0) {}

  // a) Constructor for Cartesian coordinates (real, imag)
  Complex(double real_val, double imag_val) {
    real = real_val;
    imag = imag_val;
    r = std::sqrt(real * real + imag * imag);
    phi = std::atan2(imag, real);
  }

  // a) Constructor/tagging approach for Polar coordinates (r, phi, isPolar)
  Complex(double r_val, double phi_val, bool isPolar) {
    if (isPolar) {
      r = r_val;
      phi = phi_val;
      real = r * std::cos(phi);
      imag = r * std::sin(phi);
    } else {
      real = r_val;
      imag = phi_val;
      r = std::sqrt(real * real + imag * imag);
      phi = std::atan2(imag, real);
    }
  }

  // Addition operator (from lecture)
  Complex operator+(const Complex &other) const {
    return Complex(real + other.real, imag + other.imag);
  }

  // b) Subtraction operator
  Complex operator-(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
  }

  // b) Multiplication operator: (a + bi)(c + di) = (ac - bd) + i(ad + bc)
  Complex operator*(const Complex &other) const {
    double new_real = real * other.real - imag * other.imag;
    double new_imag = real * other.imag + imag * other.real;
    return Complex(new_real, new_imag);
  }

  // c) Printing function displaying both Cartesian and Polar representations
  void print() const {
    std::cout << "Cartesian: " << real << " + i * " << imag
              << " | Polar: " << r << " * e^(i * " << phi << ")" << std::endl;
  }
};

// =============================================================================
// Problem 4.2: Pointers and references
// =============================================================================

// a) Increment using a pointer
void increment(int *address_to_number) {
  if (address_to_number != nullptr) {
    (*address_to_number)++;
  }
}

// a) Overloaded increment using a reference
void increment(int &number) {
  number++;
}

// b) Singly-linked list Element struct
struct Element {
  int value;
  Element *next;
};

int main() {
  // ---------------------------------------------------------------------------
  // Problem 4.1 d) Testing Complex numbers in main()
  // ---------------------------------------------------------------------------
  std::cout << "=== Problem 4.1: Complex Numbers ===" << std::endl;

  // Construct using Cartesian coordinates: z1 = 3 + 4i
  Complex z1(3.0, 4.0);
  std::cout << "z1 (Cartesian ctor): ";
  z1.print();

  // Construct using Polar coordinates: r = 2.0, phi = pi / 4 (~0.785398 rad)
  double pi = std::acos(-1.0);
  Complex z2(2.0, pi / 4.0, true);
  std::cout << "z2 (Polar ctor):     ";
  z2.print();

  // Addition, Subtraction, Multiplication
  Complex sum = z1 + z2;
  std::cout << "z1 + z2:             ";
  sum.print();

  Complex diff = z1 - z2;
  std::cout << "z1 - z2:             ";
  diff.print();

  Complex prod = z1 * z2;
  std::cout << "z1 * z2:             ";
  prod.print();

  std::cout << std::endl;

  // ---------------------------------------------------------------------------
  // Problem 4.2 a) & b) Testing Pointers, References, and Element in main()
  // ---------------------------------------------------------------------------
  std::cout << "=== Problem 4.2: Pointers and References ===" << std::endl;

  Element first = {1, nullptr};
  Element second = {2, &first};
  std::cout << "second.next->value: " << second.next->value << std::endl;
  std::cout << "second.next->next:  " << second.next->next << std::endl;

  int i = 5;
  increment(&i);
  std::cout << "After increment(&i): " << i << std::endl;
  increment(i);
  std::cout << "After increment(i):  " << i << std::endl;
  increment(&i);
  std::cout << "After increment(&i): " << i << std::endl;

  return 0;
}
