# Exercise 3: Arrays and Structs — Problems & Solutions

---

## Problem 3.1: Arrays

Write your functions into the file `Exercise1_Arrays/Arrays.cpp`. Use `main.cpp` to test your functions. Feel free to take a look at the file `Exercise1_Arrays/Arrays.h` if you need help with creating the function signatures.

---

### Task 3.1 a) Arithmetic Mean (`average`)

#### Problem
Given an array `grades` and its length `amount_of_grades`. Write a function `average` that takes a pointer to a `double[]` array and the number of elements (length) of the array as an `int` as parameters. The function should calculate the arithmetic mean of the array entries and return it as a `double` value.

Calculation of the arithmetic mean:

$$\text{mean} = \frac{1}{n} \sum_{k=1}^{n} a_k$$

Example:

$$\frac{4 + 3 + 2 + 1}{4} = 2.5$$

#### Solution

```cpp
double average(double list[], int length) {
    if (length <= 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += list[i];
    }
    return sum / length;
}
```

---

### Task 3.1 b) Searching in a `double` Array (`compare` and `contains`)

#### Problem
Implement a function `contains` that checks whether a given value is contained in an array. Since we are working with `double` values here, we cannot use a direct `==` comparison. Therefore, proceed in two steps and first implement a helper function:

- **i) The `compare` function:** This function receives two `double` values as parameters and should return `true` if the two values differ less than `0.00001`; otherwise, the function should return `false`.
  For example, for the inputs `5.0` and `4.9`:
  $$|5.0 - 4.9| < 0.00001 \iff 0.1 < 0.00001 \implies \text{false}$$
- **ii) The `contains` function:** Write a function `contains` that receives a pointer to a `double[]` array, its length as an `int`, as well as a `double` target value. The function should return the index of the target value if it is found in the array. If this is not the case, the function returns `-1`. Be sure to use the previously implemented `compare` function for the value comparison.

#### Solution

```cpp
// i) Helper function: checks whether |a - b| < 0.00001
bool compare(double a, double b) {
    if (a < b) {
        return (b - a) < 0.00001;
    } else {
        return (a - b) < 0.00001;
    }
}

// ii) Linear search using compare()
int contains(double list[], int length, double target) {
    for (int i = 0; i < length; i++) {
        if (compare(list[i], target)) {
            return i;
        }
    }
    return -1;
}
```

---

### Task 3.1 c) Floating-Point Comparison & Passing Arrays as Pointers

#### Problem
Briefly explain (in your own words) why it is not a good idea to compare two floating-point numbers using `==`. Also explain why we only pass a pointer to the array to the functions rather than the array itself.

#### Solution

1. **Why comparing floating-point numbers with `==` is a bad idea:**
   Floating-point numbers (`float`, `double`) are stored in memory using a finite number of bits in base-2 (binary) representation (IEEE 754 standard). Many decimal fractions (such as `0.1` or `0.3`) cannot be represented *exactly* in binary, just like $1/3 = 0.333\dots$ cannot be represented with a finite number of digits in base-10. Because of tiny rounding and representation inaccuracies during arithmetic operations (e.g., `0.1 + 0.2` evaluating to `0.30000000000000004`), two values that are mathematically equal can have slightly different bit patterns. A direct `==` check compares exact bits and can therefore evaluate to `false` even when the numbers are conceptually equal. Instead, we check whether the absolute difference $|a - b|$ is smaller than a small tolerance threshold $\epsilon$ (here `0.00001`).

2. **Why we pass a pointer to the array rather than the array itself:**
   - **Memory and performance efficiency:** Copying an entire array on every function call would require allocating new memory and copying every single element, which is slow ($O(n)$ time and space) for large arrays. Passing a pointer only copies the memory address of the first element (typically 8 bytes on a 64-bit system), which is $O(1)$.
   - **C++ array decay:** In C++, raw C-style arrays (`double[]`) automatically *decay* into a pointer to their first element (`double*`) when passed as a function argument. Because a pointer only stores the starting address and carries no metadata about how many elements follow, we must also pass the `length` of the array as a separate `int` parameter.

---

### Task 3.1 d) Linear Search (`contains`) vs. Binary Search (`contains_binary_search`)

#### Problem
Compare your implementation with a binary search (`contains_binary_search`):
- Do both functions do exactly the same thing?
- How many elements are checked on average or in the worst case before the target is found?
- What condition must necessarily be fulfilled for the array so that binary search yields correct results?

#### Solution

1. **Do both functions do exactly the same thing?**
   Both functions search for `target` in the array and return its index if found, or `-1` if not found. However, they do **not** behave identically in all cases:
   - **Unsorted arrays:** `contains` (linear search) works on *any* array (sorted or unsorted), whereas `contains_binary_search` only works reliably on *sorted* arrays.
   - **Duplicate elements:** `contains` scans from index `0` left-to-right and always returns the **first** occurrence of `target`. Binary search starts in the middle and may return the index of *any* matching duplicate element depending on where `mid` lands.

2. **How many elements are checked on average or in the worst case?**
   Let $n$ be the number of elements (`length`) in the array:

   | Search Algorithm | Average Case | Worst Case | Time Complexity |
   | :--- | :--- | :--- | :--- |
   | **Linear Search (`contains`)** | $\approx \frac{n}{2}$ elements | $n$ elements (target at end or not present) | $O(n)$ |
   | **Binary Search (`contains_binary_search`)** | $\approx \log_2(n)$ elements | $\lfloor \log_2(n) \rfloor + 1$ elements (halving the search range each step) | $O(\log n)$ |

3. **What condition must necessarily be fulfilled for binary search to yield correct results?**
   The array **must be sorted** (here in ascending order, i.e., `list[0] <= list[1] <= ... <= list[n-1]`). Binary search relies on comparing `target` with the middle element `list[mid]` to discard half of the remaining search space at every step; if the array is not sorted, discarding half of the array based on `list[mid] < target` or `list[mid] > target` can discard the half that actually contains the target.

---

## Problem 3.2: Structs (`Pizza`)

*Implementation Note:* Write your code for this exercise inside the `Exercise2_Structs/Structs.h` file and test your implementation inside `main.cpp`.

---

### Task 3.2 a) Struct Declaration and Instantiation

#### Problem
Declare a `struct` named `Pizza` containing two `float` member variables:
- `diameter` (the diameter of the pizza in cm)
- `price` (the price of the pizza in Euros)

Inside your `main()` function, instantiate two `Pizza` objects using the values of your favorite pizzas (or custom example values).

---

### Task 3.2 b) Calculating Price per Square Centimeter

#### Problem
Implement the member function `price_per_cm2`, which calculates and returns the price per square centimeter of the pizza as a `float`.

Formula:

$$r = \frac{\text{diameter}}{2}, \qquad A = \pi r^2, \qquad \text{price\_per\_cm2} = \frac{\text{price}}{A}$$

---

### Task 3.2 c) Calculating Yield for Five Euros

#### Problem
Implement the member function `five_euro_get_you_x_cm2`. This method must internally utilize your `price_per_cm2` function to compute the total area (in $\text{cm}^2$) obtainable for 5.00 Euros. Return this value as a `float`.

Formula:

$$\text{five\_euro\_get\_you\_x\_cm2} = \frac{5.0}{\text{price\_per\_cm2}()}$$

#### Solution (`Exercise2_Structs/Structs.h`)

```cpp
#ifndef INC_04_EXERCISE_STRUCTS_H
#define INC_04_EXERCISE_STRUCTS_H

struct Pizza {
    // a) Member variables
    float diameter; // Diameter of the pizza in cm
    float price;    // Price of the pizza in Euros

    // b) Calculate price per square centimeter (EUR / cm^2)
    float price_per_cm2() {
        float radius = diameter / 2.0f;
        float area = radius * radius * 3.14159f;
        return price / area;
    }

    // c) Calculate total area (in cm^2) obtainable for 5.00 Euros
    float five_euro_get_you_x_cm2() {
        return 5.0f / price_per_cm2();
    }
};

#endif //INC_04_EXERCISE_STRUCTS_H
```

---

### Testing in `main()`

#### Problem
Test both methods within `main()` using your instantiated pizza objects to determine which pizza offers the best value for money!

#### Solution (`main.cpp`)

```cpp
#include <iostream>
#include "Exercise1_Arrays/Arrays.h"
#include "Exercise2_Structs/Structs.h"

int main() {
    // =========================================================================
    // Problem 3.1: Arrays
    // =========================================================================
    std::cout << "=== Problem 3.1: Arrays ===" << std::endl;

    double grades[] {1.0, 2.3, 2.3, 3.0, 3.7, 4.0};
    int amount_of_grades = 6;

    // a) Average calculation
    std::cout << "Average grade: " << average(grades, amount_of_grades) << std::endl;

    // b) i) Compare test
    std::cout << "compare(5.0, 4.9): " << (compare(5.0, 4.9) ? "true" : "false") << std::endl;
    std::cout << "compare(2.3, 2.300001): " << (compare(2.3, 2.300001) ? "true" : "false") << std::endl;

    // b) ii) & d) Linear search vs Binary search
    std::cout << "contains(2.3) index: " << contains(grades, amount_of_grades, 2.3) << std::endl;
    std::cout << "contains(1.7) index: " << contains(grades, amount_of_grades, 1.7) << std::endl;
    std::cout << "contains_binary_search(2.3) index: "
              << contains_binary_search(grades, amount_of_grades, 2.3) << std::endl;
    std::cout << "contains_binary_search(1.7) index: "
              << contains_binary_search(grades, amount_of_grades, 1.7) << std::endl;

    std::cout << std::endl;

    // =========================================================================
    // Problem 3.2: Structs (Pizza)
    // =========================================================================
    std::cout << "=== Problem 3.2: Structs (Pizza) ===" << std::endl;

    // a) Instantiate two Pizza objects
    Pizza pizza1 = {28.0f, 7.5f};
    Pizza pizza2 = {29.0f, 8.0f};

    // b) & c) Test both methods in main()
    std::cout << "Pizza 1 (" << pizza1.diameter << " cm, " << pizza1.price << " EUR):" << std::endl;
    std::cout << "  - Price per cm^2: " << pizza1.price_per_cm2() << " EUR/cm^2" << std::endl;
    std::cout << "  - Area for 5.00 EUR: " << pizza1.five_euro_get_you_x_cm2() << " cm^2" << std::endl;

    std::cout << "Pizza 2 (" << pizza2.diameter << " cm, " << pizza2.price << " EUR):" << std::endl;
    std::cout << "  - Price per cm^2: " << pizza2.price_per_cm2() << " EUR/cm^2" << std::endl;
    std::cout << "  - Area for 5.00 EUR: " << pizza2.five_euro_get_you_x_cm2() << " cm^2" << std::endl;

    if (pizza1.five_euro_get_you_x_cm2() > pizza2.five_euro_get_you_x_cm2()) {
        std::cout << "=> Pizza 1 offers the best value for money!" << std::endl;
    } else if (pizza2.five_euro_get_you_x_cm2() > pizza1.five_euro_get_you_x_cm2()) {
        std::cout << "=> Pizza 2 offers the best value for money!" << std::endl;
    } else {
        std::cout << "=> Both pizzas offer the exact same value for money!" << std::endl;
    }

    return 0;
}
```

#### Output

```text
=== Problem 3.1: Arrays ===
Average grade: 2.71667
compare(5.0, 4.9): false
compare(2.3, 2.300001): true
contains(2.3) index: 1
contains(1.7) index: -1
contains_binary_search(2.3) index: 1
contains_binary_search(1.7) index: -1

=== Problem 3.2: Structs (Pizza) ===
Pizza 1 (28 cm, 7.5 EUR):
  - Price per cm^2: 0.0121802 EUR/cm^2
  - Area for 5.00 EUR: 410.501 cm^2
Pizza 2 (29 cm, 8 EUR):
  - Price per cm^2: 0.0121117 EUR/cm^2
  - Area for 5.00 EUR: 412.825 cm^2
=> Pizza 2 offers the best value for money!
```

