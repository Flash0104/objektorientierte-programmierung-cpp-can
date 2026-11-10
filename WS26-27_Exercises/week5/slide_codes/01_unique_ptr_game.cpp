// Week 5 - Slides 6-15 ("unique_ptr and the Game Hero Example")
// Topics:
//   - RAII (Resource Acquisition Is Initialization) (Slide 2)
//   - std::unique_ptr<T> exclusive ownership (Slide 6)
//   - Struct Player with constructor/destructor (Slide 8)
//   - Factory function std::make_unique<Player> (Slides 9-10)
//   - The auto keyword and type deduction (Slides 12-14)
//   - Ownership transfer via std::move() (Slide 6)

#include <iostream>
#include <memory>
#include <string>

// Slide 8: Player struct for our game
struct Player {
    std::string name;

    // Constructor (Slide 8)
    Player(std::string n) : name(n) {
        std::cout << ">>> " << name << " enters the game.\n";
    }

    // Destructor (Slide 8)
    ~Player() {
        std::cout << "<<< " << name << " leaves the game (automatically deleted!).\n";
    }
};

// Slide 9: spawnHero function demonstrating automatic cleanup
void spawnHero() {
    std::cout << "\n--- spawnHero() begins ---\n";

    // Modern creation using std::make_unique (Slide 9-10, 14):
    auto hero = std::make_unique<Player>("Aragorn");

    // Access members via the -> operator:
    std::cout << "Current hero: " << hero->name << "\n";

    // Exclusive ownership demonstration (Slide 6):
    // auto heroCopy = hero; // COMPILE ERROR: std::unique_ptr cannot be copied!

    // Transferring ownership via std::move():
    std::unique_ptr<Player> partyLeader = std::move(hero);
    if (!hero) {
        std::cout << "Ownership transferred! 'hero' is now empty (nullptr).\n";
        std::cout << "Party leader is now: " << partyLeader->name << "\n";
    }

    std::cout << "--- spawnHero() ends (partyLeader goes out of scope) ---\n";
    // At this closing brace, partyLeader is destroyed and Player destructor is called automatically!
}

int main() {
    std::cout << "Game starting...\n";

    // Slide 11: Call spawnHero()
    spawnHero();

    std::cout << "\nGame finished.\n";
    return 0;
}

