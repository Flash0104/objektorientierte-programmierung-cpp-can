// Week 2 - Slides 37-45 ("Char and String")
// Topics:
//   - Char as integer under the hood, incrementing chars (Slide 37)
//   - Extending strings with += (Slides 40, 41)
//   - Concatenating strings with + (Slide 42)
//   - Indexing with [] vs .at(), out_of_range exception (Slides 43-44)

#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    std::cout << "=== Example 1: Char arithmetic (Slide 37) ===" << std::endl;
    char a = 'a';
    std::cout << "Initial char a: " << a << std::endl;
    char c = 'c';
    c++; // 'c' (ASCII 99) becomes 'd' (ASCII 100)
    std::cout << "Char 'c' after c++: " << c << std::endl;

    std::cout << "\n=== Example 2: Extending strings with += (Slides 40-41) ===" << std::endl;
    // Extending with another string (no new string object, memory extended)
    std::string s = "Hello ";
    s += "World.";
    std::cout << "Extended with string: " << s << std::endl;

    // Extending with a single char
    std::string s_char = "Hello";
    char ex = '!';
    s_char += ex;
    std::cout << "Extended with char: " << s_char << std::endl;

    std::cout << "\n=== Example 3: Concatenating strings with + (Slide 42) ===" << std::endl;
    std::string s1 = "Hello ";
    std::string s2 = "World.";
    std::string s3 = s1 + s2; // creates new string s3, s1 and s2 unchanged
    std::cout << "Concatenated string s3: " << s3 << std::endl;

    std::cout << "\n=== Example 4: Indexing: [] vs .at() (Slides 43-44) ===" << std::endl;
    std::string sample = "Hello World!";
    std::cout << "sample[0]:    " << sample[0] << std::endl;
    std::cout << "sample.at(0): " << sample.at(0) << std::endl;
    std::cout << "sample[6]:    " << sample[6] << std::endl;
    std::cout << "sample.at(6): " << sample.at(6) << std::endl;

    // Slide 44: Out of bounds access
    std::cout << "\nDemonstrating bounds checking with sample.at(42):" << std::endl;
    try {
        char out_char = sample.at(42); // throws std::out_of_range
        std::cout << out_char << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception safely: " << e.what() << std::endl;
        std::cout << "(Note: sample[42] would cause undefined behaviour without bounds checking!)" << std::endl;
    }

    return 0;
}

