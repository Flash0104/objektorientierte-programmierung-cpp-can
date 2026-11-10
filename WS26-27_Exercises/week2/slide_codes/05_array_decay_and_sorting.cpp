// Week 2 - Slides 48-63 ("Arrays, Sorting, and Pointer Decay")
// Topics:
//   - Array creation and indexing (Slide 49-50)
//   - Syntactic equivalence: numbers[i] == *(numbers + i) == i[numbers] (Slide 52)
//   - Creating randomly populated array & sorting with Selection Sort (Slides 54-56)
//   - Determining array length with sizeof(arr) / sizeof(arr[0]) (Slide 57-58)
//   - The POINTER DECAY trap when passing arrays to functions (Slides 59-62)
//   - Correct approach: passing pointer + explicit length (Slide 63)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility> // for std::swap

// Slide 59: The WRONG way that triggers pointer decay
// In C and C++, array parameters in function declarations like float x[]
// decay silently into a pointer: float* x.
// Therefore, sizeof(x) returns sizeof(float*) (typically 8 bytes on 64-bit systems),
// NOT the array size!
void printArrayWrong(float x[]) {
    std::cout << "[printArrayWrong] sizeof(x) evaluates to pointer size: " << sizeof(x) << " bytes" << std::endl;
    // Attempting: for(int i = 0; i < sizeof(x)/sizeof(float); i++)
    // evaluates to 8 / 4 = 2 iterations only!
}

// Slide 63: The RIGHT way
// Show that you have understood arrays in C/C++: pass the pointer and pass the size explicitly.
void printArrayCorrect(const float* x, int length) {
    std::cout << "[printArrayCorrect] Array elements: ";
    for (int i = 0; i < length; ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Example 1: Syntactic Sugar for Array Indexing (Slide 52) ===" << std::endl;
    int testArr[5] = {10, 20, 30, 40, 50};
    std::cout << "testArr[2]:       " << testArr[2] << std::endl;
    std::cout << "*(testArr + 2):   " << *(testArr + 2) << std::endl;
    std::cout << "*(2 + testArr):   " << *(2 + testArr) << std::endl;
    std::cout << "2[testArr]:       " << 2[testArr] << " (syntactic quirk in C++)" << std::endl;

    std::cout << "\n=== Example 2: Random Array & Sorting (Slides 54-56) ===" << std::endl;
    const int N = 10;
    int numbers[N];
    srand((unsigned)time(0)); // seed RNG

    std::cout << "Random numbers: ";
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 100;
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Slide 56: Simple selection/bubble sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (numbers[j] < numbers[i]) {
                std::swap(numbers[i], numbers[j]);
            }
        }
    }

    std::cout << "Sorted numbers: ";
    for (int i = 0; i < N; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Example 3: sizeof and Pointer Decay (Slides 58-63) ===" << std::endl;
    float floats[5] = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    
    // In main (where floats is a local array, not yet decayed):
    int calculated_len = sizeof(floats) / sizeof(float);
    std::cout << "In main: sizeof(floats) = " << sizeof(floats) 
              << " bytes -> length = " << calculated_len << std::endl;

    // Passing to function:
    printArrayWrong(floats);
    printArrayCorrect(floats, calculated_len);

    return 0;
}

