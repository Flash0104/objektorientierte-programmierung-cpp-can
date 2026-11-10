// Week 3 - Slides 7-8 ("Point Struct and Constructors")
// Topics:
//   - Defining struct Point with coordinates x and y
//   - Modern C++ Member Initializer List (Slide 7)
//   - Older C-like body assignment style (Slide 8)
//   - Default constructor vs parameterized constructor

#include <iostream>

// Slide 7: Modern, efficient C++ style using Member Initializer Lists
// The member initializer list initializes members directly upon creation,
// avoiding default-initialization followed by reassignment.
struct PointModern {
    double x;
    double y;

    // Default constructor: called without arguments
    PointModern() : x(0.0), y(0.0) {
        std::cout << "  PointModern default constructor called -> (" << x << ", " << y << ")\n";
    }

    // Parameterized constructor
    PointModern(double _x, double _y) : x(_x), y(_y) {
        std::cout << "  PointModern parameterized constructor called -> (" << x << ", " << y << ")\n";
    }
};

// Slide 8: Older C++ / Java / C# style with assignment in constructor body
struct PointOldStyle {
    double x;
    double y;

    PointOldStyle() {
        x = 0.0;
        y = 0.0;
    }

    PointOldStyle(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

int main() {
    std::cout << "=== Creating PointModern instances (Slide 7) ===" << std::endl;
    PointModern p1;           // calls default constructor
    PointModern p2(3.5, 7.2); // calls parameterized constructor

    std::cout << "\n=== Creating PointOldStyle instances (Slide 8) ===" << std::endl;
    PointOldStyle p3;
    PointOldStyle p4(10.0, 20.0);
    std::cout << "p3: (" << p3.x << ", " << p3.y << ")\n";
    std::cout << "p4: (" << p4.x << ", " << p4.y << ")\n";

    return 0;
}

