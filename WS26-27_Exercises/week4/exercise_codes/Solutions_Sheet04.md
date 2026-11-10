# Exercise 4: Structs, Pointers and References — Problems & Solutions

---

## Problem 4.1: Computing with Complex Numbers

Consider the C++ structure `Complex` as introduced in the lecture slide, representing complex numbers with real and imaginary parts, including operator overloading for addition.

Extend the `Complex` struct with the following functionality:

---

### Task 4.1 a) Polar Coordinate Member Variables & Constructors

#### Problem
Add two additional member variables `double r` (magnitude) and `double phi` (phase angle in radians). Implement two constructor options:
- A constructor for Cartesian coordinates `(real, imag)` that automatically calculates the polar coordinates $r = \sqrt{\text{real}^2 + \text{imag}^2}$ and $\varphi = \text{atan2}(\text{imag}, \text{real})$.
- A constructor/tagging approach for Polar coordinates `(r, phi, bool isPolar = true)` that automatically calculates the Cartesian coordinates $\text{real} = r \cdot \cos(\varphi)$ and $\text{imag} = r \cdot \sin(\varphi)$.
*(Hint: Use `std::sqrt`, `std::atan2`, `std::cos`, and `std::sin` from `<cmath>`)*

#### Solution

```cpp
// Cartesian constructor: given (real, imag), computes (r, phi)
Complex(double real_val, double imag_val) {
  real = real_val;
  imag = imag_val;
  r = std::sqrt(real * real + imag * imag);
  phi = std::atan2(imag, real);
}

// Polar constructor (tagged with bool isPolar): given (r, phi), computes (real, imag)
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
```
> **Note on C++ Constructor Overloading:** Because both Cartesian `(real, imag)` and Polar `(r, phi)` take two `double` arguments, C++ cannot distinguish two constructors with the exact same parameter types `(double, double)`. Adding the 3rd tag parameter `bool isPolar` resolves the overload so `Complex(3.0, 4.0)` calls the Cartesian constructor and `Complex(2.0, pi / 4.0, true)` calls the Polar constructor.

---

### Task 4.1 b) Subtraction and Multiplication Operators

#### Problem
Overload the `-` and `*` operators for two complex numbers, ensuring all member variables are properly updated.

Formulas:
- **Addition:** $(a + bi) + (c + di) = (a + c) + i(b + d)$
- **Subtraction:** $(a + bi) - (c + di) = (a - c) + i(b - d)$
- **Multiplication:** $(a + bi)(c + di) = (ac - bd) + i(ad + bc)$

By returning `Complex(new_real, new_imag)`, the Cartesian constructor is invoked and automatically updates `real`, `imag`, `r`, and `phi`.

#### Solution

```cpp
// Addition operator
Complex operator+(const Complex &other) const {
  return Complex(real + other.real, imag + other.imag);
}

// Subtraction operator
Complex operator-(const Complex &other) const {
  return Complex(real - other.real, imag - other.imag);
}

// Multiplication operator
Complex operator*(const Complex &other) const {
  double new_real = real * other.real - imag * other.imag;
  double new_imag = real * other.imag + imag * other.real;
  return Complex(new_real, new_imag);
}
```

---

### Task 4.1 c) Printing Function

#### Problem
Extend the `print()` function to display both Cartesian representation (`real + i imag`) and Polar representation (`r * e^(i * phi)`).

#### Solution

```cpp
void print() const {
  std::cout << "Cartesian: " << real << " + i * " << imag
            << " | Polar: " << r << " * e^(i * " << phi << ")" << std::endl;
}
```

---

### Task 4.1 d) Testing in `main()`

#### Problem
Demonstrate your implementation inside `main()` by creating complex numbers using both Cartesian and polar constructors and displaying their operation results.

#### Solution

```cpp
// Construct using Cartesian coordinates: z1 = 3 + 4i
Complex z1(3.0, 4.0);
z1.print();

// Construct using Polar coordinates: r = 2.0, phi = pi / 4
double pi = std::acos(-1.0);
Complex z2(2.0, pi / 4.0, true);
z2.print();

// Display +, -, * results
Complex sum = z1 + z2;
sum.print();

Complex diff = z1 - z2;
diff.print();

Complex prod = z1 * z2;
prod.print();
```

---

## Problem 4.2: Pointers and References

---

### Task 4.2 a) `increment` via Pointer vs. Reference

#### Problem
Write a function `increment(int* address_to_number)` that increments the integer value at the given memory address. Next, write an overloaded version `increment(int& number)` that achieves the exact same result using a reference. Which of the two versions do you find easier to write and understand, and why?

#### Solution

```cpp
// Pointer version
void increment(int *address_to_number) {
  if (address_to_number != nullptr) {
    (*address_to_number)++;
  }
}

// Reference version
void increment(int &number) {
  number++;
}
```

#### Comparison: Which is easier to write and understand, and why?
The **reference version (`increment(int& number)`)** is much easier to write, read, and use safely:
1. **Cleaner syntax inside the function:** `number` behaves just like a normal variable (`number++`), whereas the pointer version requires explicit dereferencing with parentheses (`(*address_to_number)++`) because the postfix `++` operator has higher precedence than the dereference `*` operator.
2. **Cleaner call-site syntax:** Calling `increment(i)` passes `i` directly without needing the address-of operator `&` (`increment(&i)`).
3. **Null-safety:** A reference (`int&`) must always be bound to a valid existing object and cannot be `nullptr`, eliminating the risk of dereferencing a null pointer.

---

### Task 4.2 b) Linked `Element` Struct and `nullptr`

#### Problem
Declare a struct named `Element` that stores an integer `value` and a pointer to the next `Element` named `next`. Then, create two instances, `first` and `second`. `first` should store the value `1` and point to `nullptr`, while `second` should store the value `2` and point to `first`. Finally, print the value of `first` by accessing it through `second`’s `next` pointer.

#### Solution

```cpp
struct Element {
  int value;
  Element *next;
};

// Inside main():
Element first = {1, nullptr};
Element second = {2, &first};

// Print the value of 'first' by accessing it through 'second.next':
std::cout << second.next->value << std::endl; // prints 1
std::cout << second.next->next << std::endl;  // prints 0x0 (nullptr)
```

> **What is `nullptr`?**
> Introduced in C++11, `nullptr` is a type-safe pointer literal of type `std::nullptr_t` that represents a **null pointer** — a pointer that does not point to any valid memory address (often used to mark the end of a linked list, as in `first.next = nullptr`). To access a member of a struct through a pointer, we use the arrow operator `->` (`second.next->value`, which is shorthand for `(*(second.next)).value`).

