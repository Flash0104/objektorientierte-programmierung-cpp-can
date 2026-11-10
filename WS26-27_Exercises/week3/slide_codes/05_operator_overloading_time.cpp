// Week 3 - Slides 66-78 ("Operator Overloading and struct Time")
// Topics:
//   - Defining operators on user-defined types (Slide 66)
//   - Struct Time with _hour, _minute, _second (Slide 68)
//   - Sanitize helper method for handling 60s/60min overflow (Slides 71-72)
//   - Overloading operator+ (Slide 73: return by value, const parameters)
//   - Overloading operator+= (Slide 74: return by reference, modifies in place)
//   - The *this pointer explained (Slide 75)

#include <iostream>
#include <iomanip>

struct Time {
    int _hour;
    int _minute;
    int _second;

    // Constructors (Slide 68)
    Time() : _hour(0), _minute(0), _second(0) {}
    Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) {
        sanitize();
    }

    // Getter methods
    int hour() const { return _hour; }
    int minute() const { return _minute; }
    int second() const { return _second; }

    // Helper method to sanitize overflowing seconds and minutes (Slide 72)
    void sanitize() {
        while (_second >= 60) {
            _minute += 1;
            _second -= 60;
        }
        while (_minute >= 60) {
            _hour += 1;
            _minute -= 60;
        }
    }

    // Overloading operator+ (Slide 73)
    // - Takes parameter by const reference (prevents copying and modification)
    // - Method marked 'const' (does not modify current object)
    // - Returns by value (a new Time instance holding the combined result)
    Time operator+(const Time& rhs) const {
        Time result(_hour + rhs._hour, _minute + rhs._minute, _second + rhs._second);
        result.sanitize();
        return result;
    }

    // Overloading operator+= (Slide 74-75)
    // - Modifies the current object in-place
    // - Returns a reference to the current object (Time&) via return *this;
    // - Allows chaining like: (t1 += t2) += t3;
    Time& operator+=(const Time& rhs) {
        _hour += rhs._hour;
        _minute += rhs._minute;
        _second += rhs._second;
        sanitize();
        return *this; // dereference 'this' pointer to return current object by reference
    }

    void print() const {
        std::cout << std::setfill('0') << std::setw(2) << _hour << ":"
                  << std::setfill('0') << std::setw(2) << _minute << ":"
                  << std::setfill('0') << std::setw(2) << _second << std::endl;
    }
};

int main() {
    std::cout << "=== Testing Time Struct and Operator Overloading (Slides 68-75) ===" << std::endl;

    Time t1(1, 45, 50);
    Time t2(2, 30, 25);

    std::cout << "Time 1: "; t1.print();
    std::cout << "Time 2: "; t2.print();

    // Testing operator+
    Time t3 = t1 + t2;
    std::cout << "\nResult of t1 + t2 (new object): ";
    t3.print();

    // Testing operator+=
    std::cout << "\nAdding t2 to t1 using t1 += t2 (in-place modification):" << std::endl;
    t1 += t2;
    std::cout << "Time 1 is now: ";
    t1.print();

    return 0;
}

