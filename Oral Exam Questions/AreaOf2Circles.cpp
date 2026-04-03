#include <iostream>

// Defined PI for area calculation
const double PI = 3.14159265358979323846;

// Base struct requested in the exam
struct Circle {
    double radius;

    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Virtual function as requested: "circle'da virtual yaptim"
    virtual double getArea() const {
        return PI * radius * radius;
    }

    // A virtual destructor is recommended for base classes with virtual methods
    virtual ~Circle() = default;
};

// Derived struct: "bi de circle2 diye... circle2'de overrideladim"
struct Circle2 : public Circle {

    // Constructor calling base class constructor
    Circle2(double r) : Circle(r) {}

    // Overriding the virtual method from the base struct
    double getArea() const override {
        // Just as an example, this prints a message to verify it's the overridden method,
        // then calculates the standard circle area.
        std::cout << "[Circle2 Override] ";
        return PI * radius * radius;
    }
};

int main() {
    // "iki dairenin alani yani" -> Let's test area calculation for two circles
    
    // Instantiate base and derived structs
    Circle myCircle1(5.0);
    Circle2 myCircle2(10.0);

    std::cout << "--- Calculating Areas Directly ---" << std::endl;
    std::cout << "Area of myCircle1 (Circle): " << myCircle1.getArea() << std::endl;
    std::cout << "Area of myCircle2 (Circle2): " << myCircle2.getArea() << std::endl;

    std::cout << "\n--- Demonstrating Polymorphism ---" << std::endl;
    // Using base class pointers to show virtual function dispatch "gunun sonunda calisiyordu"
    Circle* ptr1 = &myCircle1;
    Circle* ptr2 = &myCircle2;

    std::cout << "Area using pointer to Circle object : " << ptr1->getArea() << std::endl;
    std::cout << "Area using pointer to Circle2 object: " << ptr2->getArea() << std::endl;

    return 0;
}
