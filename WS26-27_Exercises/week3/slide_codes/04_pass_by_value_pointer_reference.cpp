// Week 3 - Slides 25-27, 57-63 ("Passing Data: Value vs Pointer vs Reference")
// Topics:
//   - Pass-by-value overhead (Slide 25, 60)
//   - Pass-by-pointer and dereference syntax (Slide 61, 62)
//   - Pass-by-reference: the modern C++ alias solution (Slide 63)
//   - Read-only protection using const pointers/references (Slide 27)

#include <iostream>

struct DataHolder {
    int x;
};

// Solution 1: Call-by-value (Slide 60)
// Copies the entire object into function memory. High memory overhead for large structs.
DataHolder addOneByValue(DataHolder dataHolder) {
    dataHolder.x += 1;
    return dataHolder; // returns another copy
}

// Solution 2: Pass-by-pointer (Slide 61-62)
// Passes 8-byte memory address. Requires explicit dereference (*ptr).x or ptr->x
void addOneByPointer(DataHolder* dataHolder) {
    if (dataHolder != nullptr) {
        // Option 2a (Slide 61): (*dataHolder).x += 1;
        // Option 2b (Slide 62): arrow operator
        dataHolder->x += 1;
    }
}

// Solution 3: Call-by-reference (Slide 63 - Modern C++ style)
// Creates an alias to original object with zero copy overhead and clean dot syntax.
void addOneByReference(DataHolder& dataHolder) {
    dataHolder.x += 1;
}

// Slide 27: Read-only protection with const
// Best of both worlds: zero copy overhead, but protected from accidental modification!
void inspectData(const DataHolder& dataHolder) {
    std::cout << "Inspecting DataHolder.x = " << dataHolder.x << std::endl;
    // dataHolder.x = 100; // COMPILER ERROR: Protected by const!
}

int main() {
    std::cout << "=== Solution 1: Call-by-value (Slide 60) ===" << std::endl;
    DataHolder val1 = {1};
    val1 = addOneByValue(val1);
    std::cout << "val1.x after addOneByValue: " << val1.x << std::endl;

    std::cout << "\n=== Solution 2: Pass-by-pointer (Slide 61-62) ===" << std::endl;
    DataHolder val2 = {1};
    addOneByPointer(&val2); // pass address with &
    std::cout << "val2.x after addOneByPointer: " << val2.x << std::endl;

    std::cout << "\n=== Solution 3: Call-by-reference (Slide 63) ===" << std::endl;
    DataHolder val3 = {1};
    addOneByReference(val3); // clean syntax, operates directly on original
    std::cout << "val3.x after addOneByReference: " << val3.x << std::endl;

    std::cout << "\n=== Read-only const reference (Slide 27) ===" << std::endl;
    inspectData(val3);

    return 0;
}

