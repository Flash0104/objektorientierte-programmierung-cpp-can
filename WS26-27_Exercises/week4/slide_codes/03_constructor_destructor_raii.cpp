// Week 4 - Slides 37-41 ("Constructors and Destructors: Stack vs Heap Objects")
// Topics:
//   - Constructor: called automatically when object is initialized (Slide 37)
//   - Destructor: called automatically when object is destroyed / cleaned up (~Thing)
//   - Stack allocation: automatic destructor execution when leaving scope (Slide 39)
//   - Heap allocation: 'new' invokes constructor, 'delete' invokes destructor (Slide 40-41)

#include <iostream>
#include <cstdlib>

struct Thing {
    int size;
    void* memory;

    // Constructor (Slide 38)
    Thing(int s) : size(s) {
        std::cout << "  [Constructor] Creating Thing of size " << size << std::endl;
        memory = std::malloc(size);
    }

    // Destructor (Slide 38)
    // Marked with tilde '~' and has no parameters or return type
    ~Thing() {
        std::cout << "  [Destructor] Cleaning up Thing of size " << size << std::endl;
        std::free(memory);
        memory = nullptr;
    }
};

void testStackAllocation() {
    std::cout << "\n--- Entering testStackAllocation() scope ---" << std::endl;
    // Slide 39: Two objects created on the STACK:
    Thing t1(20);
    Thing t2(30);
    std::cout << "--- Exiting testStackAllocation() scope ---" << std::endl;
    // When scope ends, destructors for t2 and t1 are called automatically in reverse order!
}

void testHeapAllocation() {
    std::cout << "\n--- Entering testHeapAllocation() scope ---" << std::endl;
    // Slide 40: Object created on the HEAP using 'new'
    Thing* heapThing = new Thing(50);

    // Slide 40-41 rule:
    // "Always match every new with a delete to avoid memory leaks!"
    std::cout << "Explicitly calling delete on heapThing:" << std::endl;
    delete heapThing; // invokes ~Thing() and frees heap memory
    heapThing = nullptr;

    std::cout << "--- Exiting testHeapAllocation() scope ---" << std::endl;
}

int main() {
    std::cout << "=== Part 1: Stack Allocation and Automatic Cleanup (Slide 39) ===" << std::endl;
    testStackAllocation();

    std::cout << "\n=== Part 2: Heap Allocation with new and delete (Slide 40-41) ===" << std::endl;
    testHeapAllocation();

    return 0;
}

