// Week 4 - Slides 43-62 ("Memory Leaks, Garbage Collection vs Reference Counting")
// Topics:
//   - Memory leak: loss of pointer to heap data (Slide 43)
//   - Why C++ doesn't use a heavy Garbage Collector (stop-the-world overhead) (Slides 45-51)
//   - The Reference Counting solution (Slide 52)
//   - Overview of the 4 Memory Sections in C++ (Slide 62): Text, Data, Heap, Stack

#include <iostream>

struct Resource {
    int id;
    Resource(int i) : id(i) {
        std::cout << "  Resource #" << id << " allocated on Heap.\n";
    }
    ~Resource() {
        std::cout << "  Resource #" << id << " destroyed from Heap.\n";
    }
};

// Simplified illustration of Reference Counting principle (Slide 52)
// Tracks how many active variables reference a shared object.
class SimpleRefCountedBlock {
private:
    Resource* res;
    int ref_count;

public:
    SimpleRefCountedBlock(int id) : res(new Resource(id)), ref_count(1) {
        std::cout << "[RefCount] Resource #" << id << " created. ref_count = " << ref_count << "\n";
    }

    void addRef() {
        ref_count++;
        std::cout << "[RefCount] New reference added. ref_count = " << ref_count << "\n";
    }

    void releaseRef() {
        ref_count--;
        std::cout << "[RefCount] Reference released. ref_count = " << ref_count << "\n";
        if (ref_count == 0) {
            std::cout << "[RefCount] ref_count reached 0 -> automatically destroying resource!\n";
            delete res;
            res = nullptr;
        }
    }

    int getRefCount() const { return ref_count; }
};

int main() {
    std::cout << "=== Slide 62: The 4 Memory Sections in C++ ===" << std::endl;
    std::cout << "1. Text Section: Compiled machine instructions\n"
              << "2. Data Section: Global and static variables\n"
              << "3. Heap Section: Dynamically allocated memory (new/delete, malloc/free)\n"
              << "4. Stack Section: Local variables and function frames\n" << std::endl;

    std::cout << "=== Slide 52: Concept of Reference Counting ===" << std::endl;
    SimpleRefCountedBlock block(101); // ref_count = 1

    {
        std::cout << "\nInside an inner scope (a second variable references the block):" << std::endl;
        block.addRef(); // ref_count = 2
        std::cout << "Current active owners: " << block.getRefCount() << std::endl;
        block.releaseRef(); // inner scope ends, ref_count = 1
    }

    std::cout << "\nBack in main scope. Current active owners: " << block.getRefCount() << std::endl;
    std::cout << "Main scope ends:" << std::endl;
    block.releaseRef(); // ref_count = 0 -> deleted!

    return 0;
}

