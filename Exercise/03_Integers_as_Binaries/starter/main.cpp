#include <iostream>
bool nth_bit_is_zero(int, int);
void print_int_as_binary(int);


int main() {
    std::cout << "=== Exercise 1: 2's Complement (8 bits = 1 byte) ===" << std::endl;
    
    // Array of numbers to print and their labels
    int numbers[] = {13, -8, 0};
    char labels[] = {'a', 'b', 'c'};
    
    // Loop through each number and print its 8-bit representation
    for (int n = 0; n < 3; n++) {
        std::cout << labels[n] << ") " 
                  << (numbers[n] >= 0 ? "(+) " : "(-) ") 
                  << (numbers[n] >= 0 ? numbers[n] : -numbers[n]) 
                  << " = ";
        
        // Print only lowest 8 bits to show 1 byte representation
        for (int i = 7; i >= 0; i--) {
            std::cout << ((numbers[n] & (1 << i)) ? "1" : "0");
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n=== Exercise 2: Binary Representation (full int size) ===" << std::endl;
    print_int_as_binary(-8);
    print_int_as_binary(8);
    print_int_as_binary(0);
    print_int_as_binary(13);
    
    return 0;
}

bool nth_bit_is_zero(int number, int n){
    // Step 1: Create a mask by shifting 1 left by n positions
    // Example: if n=3, then temp = 1 << 3 = 8 = 00001000 in binary
    int temp = 1 << n;
    
    // Step 2: Use bitwise AND (&) to check if the nth bit is set
    // If (number & temp) equals 0, the nth bit is 0 (zero)
    // If (number & temp) is not 0, the nth bit is 1 (not zero)
    // Note: Function returns true if bit is NOT zero
    return (number & temp) != 0;
}

void print_int_as_binary(int number) {
    // Use sizeof(<datatype>) to get the size in bytes, then multiply by 8 to get bits
    // sizeof(int) returns the number of bytes an int occupies (typically 4 bytes = 32 bits)
    int num_bits = sizeof(int) * 8;
    
    // Print the number first for reference
    std::cout << number << " in binary: ";
    
    // Loop through each bit from most significant bit (MSB) to least significant bit (LSB)
    // Start from the highest bit index (num_bits - 1) and go down to 0
    for (int i = num_bits - 1; i >= 0; i--) {
        // Create a mask with only the i-th bit set to 1 by shifting 1 left by i positions
        // Use bitwise AND (&) to check if the i-th bit of number is set
        // If (number & (1 << i)) is non-zero, the bit is 1; otherwise it's 0
        if (number & (1 << i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
        
        // Add a space every 4 bits for better readability
        // Example: 1111 0000 1010 0101
        if (i % 4 == 0 && i > 0) {
            std::cout << " ";
        }
    }
    
    std::cout << std::endl;
}
