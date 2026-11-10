// Week 1 - Slides 35-37 ("Getting user input")
// Topic: Modern, safe C++ streams vs old, unsafe C-style input methods
//
// Modern C++ streams (std::getline with std::string) automatically handle buffer
// sizing dynamically in memory, preventing dangerous buffer overflows that
// occur with legacy C functions like gets() or scanf("%s").

#include <iostream>
#include <string>

int main() {
    std::cout << "=== Example 1: Safe user input using std::getline (Slide 35) ===" << std::endl;
    std::string mystr;
    std::cout << "What is your name? ";
    
    // std::getline reads a full line until newline, dynamically sizing mystr:
    if (std::getline(std::cin, mystr)) {
        std::cout << "Welcome " << mystr << ".\n";
    }

    std::cout << "\n=== Example 2: Character-level input using cin.get (Slide 36) ===" << std::endl;
    std::cout << "Enter a single character: ";
    char ch;
    std::cin.get(ch);
    std::cout << "You entered character: '" << ch << "' (ASCII code: " << int(ch) << ")\n";

    /*
     * Slide 36 Summary of Input Options:
     * -------------------------------------------------------------
     * Safe & Modern:
     *   - std::getline(std::cin, str)   -> dynamically manages std::string
     *   - std::cin.get(char_variable)   -> reads single character safely
     *   - std::getline(file_stream, str)-> reads from file streams
     *
     * Relatively Safe:
     *   - cin.getline(buffer, size)     -> size limited C-string
     *   - scanf_s("%s", buffer, size)   -> bounded scanf extension
     *
     * Unsafe (Vulnerable to Buffer Overflow):
     *   - cin >> str (into char buffer) -> no size limit
     *   - scanf("%s", buffer)           -> buffer overflow risk
     *   - gets(buffer)                  -> removed in modern C++ (extremely dangerous)
     */

    return 0;
}

