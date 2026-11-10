#include <iostream>
#include <memory>
#include <string>

struct Item {
  std::string name;

  Item(std::string n) : name(n) {
    std::cout << "  [Item Info] " << name << " has been created.\n";
  }

  ~Item() {
    std::cout << "  [Item Info] " << name
              << " has been permanently destroyed!\n";
  }
};

void teamAdventure() {
  std::cout << "--- Start of the Adventure ---\n";

  // Modern creation of the sword using std::make_shared
  auto sharedSword = std::make_shared<Item>("Excalibur");
  std::cout << "Number of owners (use_count): " << sharedSword.use_count()
            << "\n";

  {
    // A second player enters the block, and both players share the sword
    std::shared_ptr<Item> player2Sword = sharedSword;

    std::cout << "Player 2 picks up the sword. Number of owners: "
              << sharedSword.use_count() << "\n";

    // Both smart pointers point to the same object
    std::cout << "Sword name accessed through Player 2: " << player2Sword->name
              << "\n";
  }

  // player2Sword goes out of scope and is destroyed.
  // Excalibur continues to exist because sharedSword
  // inside teamAdventure() still owns it!

  std::cout << "Player 2 has left the room. Number of owners: "
            << sharedSword.use_count() << "\n";

  std::cout << "--- End of the Adventure ---\n";

  // sharedSword goes out of scope here.
  // No owners remain, so the Item destructor is called automatically.
}

int main() {
  teamAdventure();
  std::cout << "Program finished.\n";
}