#include <iostream>
#include <queue>
#include <vector>

// Exercise 1a: Struct Item
struct Item {
private:
  double price;

public:
  Item(double p) : price(p) {}

  double getPrice() const { return price; }
};

// Exercise 1b: Struct Purchase
struct Purchase {
  std::vector<Item> items;

  void add_item(Item i) { items.push_back(i); }
};

// Exercise 2a: Class Cashier
class Cashier {
private:
  std::queue<Purchase> checkoutCounter;

public:
  // Exercise 2b: placePurchase
  void placePurchase(Purchase p) {
    std::cout << "Customer placed a purchase on the counter." << std::endl;
    checkoutCounter.push(p);
  }

  // Exercise 2c: collectPurchase
  void collectPurchase() {
    if (checkoutCounter.empty()) {
      std::cout << "No purchases to collect." << std::endl;
      return;
    }

    // Get the front purchase
    Purchase current = checkoutCounter.front();

    // Calculate total for demonstration
    double total = 0;
    for (const auto &item : current.items) {
      total += item.getPrice();
    }
    std::cout << "Cashier collecting purchase. Total price: " << total
              << std::endl;

    // Remove from queue
    checkoutCounter.pop();
  }
};

int main() {
  // Test the implementation
  std::cout << "--- Checkout System Test ---" << std::endl;

  // Create Items
  Item apple(0.99);
  Item bread(2.50);
  Item milk(1.20);

  // Create Purchases
  Purchase customer1;
  customer1.add_item(apple);
  customer1.add_item(bread);

  Purchase customer2;
  customer2.add_item(milk);
  customer2.add_item(bread);
  customer2.add_item(apple);

  // Create Cashier
  Cashier myCashier;

  // Place purchases
  myCashier.placePurchase(customer1);
  myCashier.placePurchase(customer2);

  std::cout << "\n--- Processing Queue ---" << std::endl;

  // Collect purchases
  myCashier.collectPurchase();
  myCashier.collectPurchase();

  // Try empty
  myCashier.collectPurchase();

  return 0;
}
