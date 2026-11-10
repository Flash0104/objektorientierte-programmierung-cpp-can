// Week 5 - Slide 5 ("weak_ptr and Breaking Circular Dependencies")
// Topics:
//   - Why std::weak_ptr goes together with std::shared_ptr (Slide 5)
//   - Circular reference problem: two objects holding shared_ptr to each other never reach ref_count == 0 (memory leak!)
//   - Solution: using std::weak_ptr which observes an object without incrementing its reference count

#include <iostream>
#include <memory>
#include <string>

struct Companion; // forward declaration

struct Hero {
    std::string name;
    // Using std::shared_ptr here:
    std::shared_ptr<Companion> companion;

    Hero(std::string n) : name(n) {
        std::cout << "  Hero " << name << " created.\n";
    }
    ~Hero() {
        std::cout << "  Hero " << name << " destroyed.\n";
    }
};

struct Companion {
    std::string name;
    // Using std::weak_ptr here to PREVENT circular reference / memory leak:
    // If this were std::shared_ptr<Hero>, neither Hero nor Companion would ever be destroyed!
    std::weak_ptr<Hero> hero;

    Companion(std::string n) : name(n) {
        std::cout << "  Companion " << name << " created.\n";
    }
    ~Companion() {
        std::cout << "  Companion " << name << " destroyed.\n";
    }
};

void runAdventure() {
    std::cout << "--- runAdventure() start ---\n";
    auto aragorn = std::make_shared<Hero>("Aragorn");
    auto legolas = std::make_shared<Companion>("Legolas");

    aragorn->companion = legolas;
    legolas->hero = aragorn; // weak_ptr does not increase ref_count of aragorn!

    std::cout << "Aragorn use_count: " << aragorn.use_count() << "\n";
    std::cout << "Legolas use_count: " << legolas.use_count() << "\n";

    // Accessing through weak_ptr requires locking it into a temporary shared_ptr:
    if (auto sharedHero = legolas->hero.lock()) {
        std::cout << "Legolas's hero is: " << sharedHero->name << "\n";
    }

    std::cout << "--- runAdventure() end ---\n";
    // Both objects go out of scope and are properly destroyed because there is no circular shared_ptr cycle!
}

int main() {
    runAdventure();
    std::cout << "Program finished cleanly.\n";
    return 0;
}

