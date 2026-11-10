// Week 2 - Slides 25-27 ("Bitwise Operations & Hardware Registers")
// Topics:
//   - Bitwise AND (&), OR (|), XOR (^), NOT (~), shift left (<<), shift right (>>)
//   - Practical microcontroller example: Data Direction Register B (DDRB)
//     and Port B Data Register (PORTB)

#include <iostream>
#include <bitset>
#include <cstdint>

// Simulate the Arduino pin constant
constexpr uint8_t PB5 = 5;

int main() {
    std::cout << "=== Bitwise Operations in Embedded Systems (Slide 26-27) ===\n" << std::endl;

    // Suppose DDRB and PORTB have some existing configuration:
    uint8_t DDRB  = 0b00011001; // initial state
    uint8_t PORTB = 0b00001001; // initial state

    std::cout << "Initial DDRB:  " << std::bitset<8>(DDRB) << std::endl;
    std::cout << "Initial PORTB: " << std::bitset<8>(PORTB) << std::endl;

    // 1. Set bit PB5 to 1 (Output mode in DDRB, Turn ON in PORTB):
    // Using bitwise OR (|) with a bitmask created by (1 << PB5)
    std::cout << "\nSetting bit PB5 (Pin 5 OUTPUT and HIGH):" << std::endl;
    DDRB  |= (1 << PB5);
    PORTB |= (1 << PB5);
    std::cout << "DDRB  |= (1 << PB5) -> " << std::bitset<8>(DDRB) << " (PB5 is 1)" << std::endl;
    std::cout << "PORTB |= (1 << PB5) -> " << std::bitset<8>(PORTB) << " (PB5 is 1)" << std::endl;

    // 2. Clear bit PB5 to 0 (Turn OFF):
    // Using bitwise AND (&) with the inverted bitmask ~(1 << PB5)
    std::cout << "\nClearing bit PB5 (Turn OFF):" << std::endl;
    DDRB  &= ~(1 << PB5);
    PORTB &= ~(1 << PB5);
    std::cout << "DDRB  &= ~(1 << PB5) -> " << std::bitset<8>(DDRB) << " (PB5 is 0)" << std::endl;
    std::cout << "PORTB &= ~(1 << PB5) -> " << std::bitset<8>(PORTB) << " (PB5 is 0)" << std::endl;

    // 3. Toggle bit PB5:
    // Using bitwise XOR (^)
    PORTB ^= (1 << PB5);
    std::cout << "\nToggling bit PB5 with XOR (^): " << std::bitset<8>(PORTB) << std::endl;

    return 0;
}

