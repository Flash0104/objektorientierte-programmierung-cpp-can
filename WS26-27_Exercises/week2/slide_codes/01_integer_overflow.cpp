// Week 2 - Slides 12-17 ("Integer Numbers and Overflow")
// Topics:
//   - Summing integers up to 100 (Slide 12)
//   - Finding the largest signed integer using overflow (Slide 14)
//   - Fixed-width integer types from <cstdint> (Slide 16-17)

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "=== Example 1: Summing numbers up to 100 (Slide 12) ===" << std::endl;
    int sum = 0;
    for (int k = 1; k <= 100; k++) {
        sum = sum + k;
    }
    std::cout << "Sum: " << sum << std::endl; // 5050

    std::cout << "\n=== Example 2: Finding largest signed int via overflow (Slide 14) ===" << std::endl;
    // In two's complement, incrementing the maximum positive integer overflows into negative values.
    int largest = 1;
    while (largest > 0) {
        largest++;
    }
    // Now largest is the most negative number (-2147483648).
    // Subtracting 1 brings it back to the maximum positive number (2147483647).
    largest--;
    std::cout << "Largest standard int: " << largest << std::endl;

    std::cout << "\n=== Example 3: Predictable widths with <cstdint> (Slide 16-17) ===" << std::endl;
    int32_t largest_int32 = 1;
    while (largest_int32 > 0) {
        largest_int32++;
    }
    largest_int32--;
    std::cout << "Largest int32_t: " << largest_int32 << std::endl;

    std::cout << "Sizes of fixed-width types in bytes:" << std::endl;
    std::cout << "  int8_t:   " << sizeof(int8_t) << " byte  (range: -128 to 127)" << std::endl;
    std::cout << "  uint8_t:  " << sizeof(uint8_t) << " byte  (range: 0 to 255)" << std::endl;
    std::cout << "  int16_t:  " << sizeof(int16_t) << " bytes (range: -32768 to 32767)" << std::endl;
    std::cout << "  int32_t:  " << sizeof(int32_t) << " bytes (range: ~ -2.14B to +2.14B)" << std::endl;
    std::cout << "  int64_t:  " << sizeof(int64_t) << " bytes" << std::endl;

    return 0;
}

