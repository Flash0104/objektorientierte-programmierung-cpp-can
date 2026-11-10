// Week 3 - Slides 30-54 ("Pointers and Low-Level Memory Reinterpretation")
// Topics:
//   - Address-of (&) and dereference (*) operators (Slide 30)
//   - Pointer assignment and type constraints (Slides 33-40)
//   - Reinterpreting memory across types via pointer casting (Slides 42-45)
//   - Bitwise extraction of the 32 bits of IEEE 754 float: (Value >> k) & 1 (Slides 46-54)

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "=== Example 1: Basic Pointer Operations (Slide 30, 32) ===" << std::endl;
    int x = 42;
    int* p = &x; // p holds memory address of x

    std::cout << "Value of x:              " << x << std::endl;
    std::cout << "Address of x (&x / p):   " << p << std::endl;
    std::cout << "Dereferenced value (*p): " << *p << std::endl;

    *p = 99; // overwrites value at address p directly modifying x
    std::cout << "After *p = 99, x is now: " << x << std::endl;

    std::cout << "\n=== Example 2: Reinterpreting Memory Representation (Slides 42-45) ===" << std::endl;
    float minuspi = -3.14159f;
    std::cout << "Memory size of float: " << sizeof(minuspi) << " bytes (32 bits)\n";

    // All these pointers point to the exact same memory address, but interpret the bits differently:
    float*    ptr1 = &minuspi;
    int32_t*  ptr2 = (int32_t*)&minuspi;
    uint32_t* ptr3 = (uint32_t*)&minuspi;
    uint16_t* ptr4 = (uint16_t*)&minuspi;

    std::cout << "Address: " << ptr1 << std::endl;
    std::cout << "  Interpreted as float:    " << *ptr1 << std::endl;
    std::cout << "  Interpreted as int32_t:  " << *ptr2 << std::endl;
    std::cout << "  Interpreted as uint32_t: " << *ptr3 << std::endl;
    std::cout << "  Interpreted as uint16_t: " << *ptr4 << " (only first 16 bits)" << std::endl;

    std::cout << "\n=== Example 3: Extracting the IEEE 754 Binary Bits (Slides 46-54) ===" << std::endl;
    std::cout << "Binary representation of " << minuspi << ":\n  ";
    uint32_t* bit_ptr = (uint32_t*)&minuspi;

    // Shift bit by bit from position 31 down to 0, masking with 1:
    for (int k = 31; k >= 0; k--) {
        std::cout << ((*bit_ptr >> k) & 1);
        if (k == 31 || k == 23) {
            std::cout << " "; // separate sign (1 bit), exponent (8 bits), mantissa (23 bits)
        }
    }
    std::cout << std::endl;
    std::cout << "  ^sign  ^exponent ^mantissa" << std::endl;

    return 0;
}

