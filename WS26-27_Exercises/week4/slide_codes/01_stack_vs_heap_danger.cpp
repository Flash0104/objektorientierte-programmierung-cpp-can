// Week 4 - Slides 20-29 ("Stack Frames and the Danger of Dangling Stack References")
// Topics:
//   - How stack frames work (allocated upon function entry, popped on return)
//   - Slide 24: "Never return references to stack-allocated data!"
//   - Slide 26-28: Returning stack data safely using std::array by value

#include <iostream>
#include <array>

// BAD PRACTICE (Slide 24): Returning pointer/reference to local stack memory
// When create_array_unsafe() returns, its stack frame is popped/invalidated.
// Accessing that memory causes undefined behaviour / stack corruption!
int* create_array_unsafe() {
    int localArr[5] = {1, 2, 3, 4, 5};
    (void)localArr; // suppress unused warning for demonstration
    // return localArr; // WARNING/ERROR: address of stack memory associated with local variable returned!
    return nullptr;
}

// GOOD PRACTICE (Slide 26-28): Returning std::array by value or allocating on heap
// In modern C++, std::array can be safely returned by value because the compiler
// either copies it cleanly or performs Return Value Optimization (RVO / move).
std::array<int, 5> create_array_safe() {
    std::array<int, 5> safeArray = {10, 20, 30, 40, 50};
    return safeArray;
}

int main() {
    std::cout << "=== Demonstrating Safe Stack Return (Slides 26-28) ===" << std::endl;
    std::array<int, 5> myArray = create_array_safe();

    std::cout << "Successfully retrieved safe array values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTakeaway from Slide 24 & 29:\n"
              << "Variables declared locally in a function live strictly on the STACK.\n"
              << "When the closing brace '}' of that function is reached, that memory is destroyed!\n";

    return 0;
}
