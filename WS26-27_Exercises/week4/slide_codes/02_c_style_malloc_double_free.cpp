// Week 4 - Slides 33-36 ("C-Style Heap Allocation: malloc, free, and Double Free")
// Topics:
//   - Manual heap management using malloc(size) and free(ptr)
//   - Encapsulating init and cleanup functions for user-defined structs (Slide 34)
//   - The danger of Double Free when manual cleanup is called more than once (Slide 35)

#include <iostream>
#include <cstdlib>

struct Thing {
    void* memory;
};

// Slide 34-35: Custom initialization function
void _init(Thing* bla, int size) {
    bla->memory = std::malloc(size);
    std::cout << "[_init] Allocated " << size << " bytes on the heap at " << bla->memory << std::endl;
}

// Slide 34-35: Custom delete function
void _delete(Thing** bla) {
    if (bla != nullptr && *bla != nullptr) {
        if ((*bla)->memory != nullptr) {
            std::cout << "[_delete] Freeing inner memory at " << (*bla)->memory << std::endl;
            std::free((*bla)->memory);
            (*bla)->memory = nullptr; // prevent double free of inner buffer
        }
        std::cout << "[_delete] Freeing Thing struct at " << *bla << std::endl;
        std::free(*bla);
        *bla = nullptr; // zero out pointer to prevent dangling pointer
    } else {
        std::cout << "[_delete] Warning: Pointer already null! (Safely avoided double free)\n";
    }
}

int main() {
    std::cout << "=== Allocating and Freeing using malloc/free (Slides 34-35) ===" << std::endl;

    Thing* t = (Thing*)std::malloc(sizeof(Thing));
    _init(t, 50);

    // Free the allocated memory
    _delete(&t);

    // Slide 35 demonstrates: What happens if a programmer calls _delete again?
    // In raw C, if pointers aren't nulled out, calling free() twice causes:
    // "malloc: Double free of object -> abort / crash"
    std::cout << "\nAttempting second deletion:" << std::endl;
    _delete(&t);

    std::cout << "\nWhy C++ introduced Constructors and Destructors (Slide 36):\n"
              << "Manual _init / _delete functions cannot be enforced by the compiler.\n"
              << "Programmers can easily forget to call _init or call _delete twice!\n";

    return 0;
}

