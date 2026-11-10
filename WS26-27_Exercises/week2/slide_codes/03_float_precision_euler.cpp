// Week 2 - Slides 28-34 ("Floating Point Numbers: float vs double")
// Topics:
//   - IEEE 754 32-bit float vs 64-bit double
//   - Alcohol in beer calculation (Slide 28)
//   - Euler's number approximation: e = lim (1 + 1/n)^n (Slides 30-32)
//   - Precision limitations & why floating point numbers should never be compared with == (Slide 34)

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << "=== Example 1: Alcohol in beer calculation (Slide 28) ===" << std::endl;
    std::cout << "How much Alcohol in a beer?" << std::endl;
    float amount_beverage = 0.33f;
    float alcohol_percentage = 0.047f;
    float raw_alcohol = amount_beverage * alcohol_percentage;
    std::cout << raw_alcohol << std::endl; // ~0.01551

    std::cout << "\n=== Example 2: Euler's number precision (float vs double) (Slides 30-32) ===" << std::endl;
    const double true_euler = 2.71828182845904523536;
    std::cout << std::setprecision(10);
    std::cout << "Reference e: " << true_euler << std::endl;

    // Slide 31: float calculation
    float e_float = 0.0f;
    for (int i = 1; i <= 30000; i += 5000) {
        float base = (1.0f + 1.0f / i);
        float temp = base;
        for (int x = 0; x < i - 1; ++x) {
            base = base * temp;
        }
        e_float = base;
        std::cout << "i = " << std::setw(5) << i << " -> float approx: " << e_float << std::endl;
    }

    // Slide 32: double calculation
    double e_double = 0.0;
    for (int i = 1; i <= 30000; i += 5000) {
        double base = (1.0 + 1.0 / i);
        double temp = base;
        for (int x = 0; x < i - 1; ++x) {
            base = base * temp;
        }
        e_double = base;
        std::cout << "i = " << std::setw(5) << i << " -> double approx: " << e_double << std::endl;
    }

    std::cout << "\n=== Slide 34 Warning: Never compare floats using == ===" << std::endl;
    float a = 0.1f * 3.0f;
    float b = 0.3f;
    std::cout << "0.1 * 3 == 0.3? " << (a == b ? "true" : "false") << std::endl;
    std::cout << "Correct approach (epsilon comparison): "
              << (std::abs(a - b) < 1e-6f ? "Equal within tolerance" : "Different") << std::endl;

    return 0;
}

