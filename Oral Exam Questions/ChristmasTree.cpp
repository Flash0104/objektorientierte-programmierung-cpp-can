#include <iostream>
#include <vector>

// Base class representing a Christmas tree
struct ChristmasTree {
    int numberOfTrees;
    double weight;

    // Default constructor
    ChristmasTree() : numberOfTrees(0), weight(0.0) {}

    // Parameterized constructor to initialize the member variables
    ChristmasTree(int numTrees, double w) : numberOfTrees(numTrees), weight(w) {}

    // Method to calculate total weight (weight times number of trees)
    double calculateTotalWeight() const {
        return numberOfTrees * weight;
    }
};

// Derived class (side class) inheriting from the base class
struct HalloweenTree : public ChristmasTree {
    // Constructor calling the base class constructor
    HalloweenTree(int numTrees, double w) : ChristmasTree(numTrees, w) {}
};

int main() {
    // Vector to store multiple HalloweenTree objects
    std::vector<HalloweenTree> treeShipments;

    // Creating some HalloweenTree instances and adding them to the vector
    treeShipments.push_back(HalloweenTree(5, 12.5));   // 5 trees, each weighing 12.5
    treeShipments.push_back(HalloweenTree(10, 8.2));   // 10 trees, each weighing 8.2
    treeShipments.push_back(HalloweenTree(2, 25.0));   // 2 trees, each weighing 25.0

    std::cout << "--- Halloween Tree Shipments ---\n" << std::endl;

    // Iterating through the vector to print the results
    for (size_t i = 0; i < treeShipments.size(); ++i) {
        std::cout << "Shipment " << (i + 1) << ":" << std::endl;
        std::cout << "  Number of Trees : " << treeShipments[i].numberOfTrees << std::endl;
        std::cout << "  Weight per Tree : " << treeShipments[i].weight << std::endl;
        
        // Calling the method inherited from the base class
        double total = treeShipments[i].calculateTotalWeight();
        std::cout << "  Total Weight    : " << total << "\n" << std::endl;
    }

    return 0;
}
