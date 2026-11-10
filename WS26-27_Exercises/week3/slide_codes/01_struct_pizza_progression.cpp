// Week 3 - Slides 4-18 ("Struct Pizza Progression")
// Topics:
//   - Grouping data semantically using struct (Slide 6)
//   - Adding methods inside a struct to encapsulate behaviour (DRY principle) (Slide 10-13)
//   - Creating arrays of structs (Slide 14-15)
//   - Range-based for loops with auto type deduction (Slide 16-17)

#include <iostream>

// Evolution of the Pizza comparison program across lecture slides:

// --- Final clean struct design (Slides 13-18) ---
struct Pizza {
    float price;     // in Euros
    float diameter;  // in cm

    // Method to calculate pizza area per Euro (Encapsulation / DRY principle):
    float cm_2_per_euro() const {
        float radius = diameter / 2.0f;
        return (radius * radius * 3.14159f) / price;
    }
};

int main() {
    std::cout << "=== Version 1: The Bad Way (Slide 5 - copy-paste without struct) ===" << std::endl;
    float p1_price = 8.9f, p1_diam = 29.0f;
    float p2_price = 7.9f, p2_diam = 25.0f;
    float p3_price = 9.9f, p3_diam = 30.0f;

    float r1 = p1_diam / 2.0f;
    float cm2_p1 = (r1 * r1 * 3.14159f) / p1_price;
    float r2 = p2_diam / 2.0f;
    float cm2_p2 = (r2 * r2 * 3.14159f) / p2_price;
    float r3 = p3_diam / 2.0f;
    float cm2_p3 = (r3 * r3 * 3.14159f) / p3_price;
    std::cout << "Pizza 1 value: " << cm2_p1 << " cm^2/Euro\n";
    std::cout << "Pizza 2 value: " << cm2_p2 << " cm^2/Euro\n";
    std::cout << "Pizza 3 value: " << cm2_p3 << " cm^2/Euro\n";

    std::cout << "\n=== Version 2: Grouping with Struct (Slide 9) ===" << std::endl;
    Pizza pizza_1 = {8.9f, 29.0f};
    Pizza pizza_2 = {7.9f, 25.0f};
    Pizza pizza_3 = {9.9f, 30.0f};
    std::cout << "Pizza 1 accessed with dot operator: " << pizza_1.diameter << "cm, " << pizza_1.price << "EUR\n";

    std::cout << "\n=== Version 3: Struct with Methods (Slide 10, 13) ===" << std::endl;
    std::cout << "Pizza 1: " << pizza_1.cm_2_per_euro() << " cm^2/Euro\n";
    std::cout << "Pizza 2: " << pizza_2.cm_2_per_euro() << " cm^2/Euro\n";
    std::cout << "Pizza 3: " << pizza_3.cm_2_per_euro() << " cm^2/Euro\n";

    std::cout << "\n=== Version 4: Array of Structs (Slide 14-15) ===" << std::endl;
    Pizza pizzas[3] = {
        {8.9f, 29.0f},
        {7.9f, 25.0f},
        {9.9f, 30.0f}
    };
    for (int i = 0; i < 3; i++) {
        std::cout << "Pizza " << (i + 1) << ": " << pizzas[i].cm_2_per_euro() << " cm^2/Euro\n";
    }

    std::cout << "\n=== Version 5: Modern Range-based For Loop (Slide 16-17) ===" << std::endl;
    // Uses automatic type deduction (auto) and eliminates off-by-one indexing errors:
    for (const auto& p : pizzas) {
        std::cout << p.cm_2_per_euro() << " cm^2/Euro" << std::endl;
    }

    return 0;
}
