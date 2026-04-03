// This is solely built by Can Bekiroglu in order to learn self development of
// C++ code (by typing it myself)

#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

double const pi = 3.1415;

struct Tree {
  int quantity;
  double radius;
  double height;
  double weight;
  double price;

  // default constructor
  Tree() : quantity(), radius(), height(0.0), weight(0.0), price(0.0) {}

  // parametrized constructor
  Tree(int q, double r, double h, double w, double p)
      : quantity(q), radius(r), height(h), weight(w), price(p) {}

  double calculatetotalweight() const { return quantity * weight; }

  double calculatetotalprice() const { return quantity * price; }

  double calculatethevolume_of_one_tree() const {
    return (1.0 / 3.0) * pi * radius * radius * height;
  }

  double calculatethearea_of_one_tree() const { return pi * radius * radius; }
};

struct ChristmasTree : public Tree {
  ChristmasTree(int q, double r, double h, double w, double p)
      : Tree(q, r, h, w, p) {}
};

struct HaloweenTree : public Tree {
  HaloweenTree(int q, double r, double h, double w, double p)
      : Tree(q, r, h, w, p) {}
};

int main() {
  std::vector<ChristmasTree> CT;
  std::vector<HaloweenTree> HT;

  double grandtotalweight = 0.0;
  double grandtotalprice = 0.0;
  double grandtotalvolume = 0.0;
  double grandtotalarea = 0.0;

  CT.push_back(ChristmasTree(10, 50.0, 200.0, 2000.0, 100.0));
  CT.push_back(ChristmasTree(5, 16.66, 50.0, 500.0, 50.0));

  HT.push_back(HaloweenTree(7, 10.0, 100.0, 1000.0, 75.0));
  HT.push_back(HaloweenTree(15, 20.0, 200.0, 250.0, 60.0));

  std::cout << "\n--- Christmas Tree Shipments ---\n" << std::endl;

  for (size_t i = 0; i < CT.size(); i++) {
    std::cout << "Christmas Tree Shipments " << i + 1 << std::endl;
    std::cout << "Total Weight: " << CT[i].calculatetotalweight() << std::endl;
    std::cout << "Total Price: " << CT[i].calculatetotalprice() << std::endl;
    std::cout << "Total Volume: " << CT[i].calculatethevolume_of_one_tree()
              << std::endl;
    std::cout << "Total Area: " << CT[i].calculatethearea_of_one_tree()
              << std::endl;

    grandtotalweight += CT[i].calculatetotalweight();
    grandtotalprice += CT[i].calculatetotalprice();
    grandtotalvolume += CT[i].calculatethevolume_of_one_tree();
    grandtotalarea += CT[i].calculatethearea_of_one_tree();
  }
  cout << "\nGRAND TOTALS FOR CHRISTMAS TREES" << endl;
  cout << "Grand Total Weight: " << grandtotalweight << endl;
  cout << "Grand Total Price: " << grandtotalprice << endl;
  cout << "Grand Total Volume: " << grandtotalvolume << endl;
  cout << "Grand Total Area: " << grandtotalarea << endl;

  std::cout << "\n--- Haloween Tree Shipments ---\n" << std::endl;

  for (size_t i = 0; i < HT.size(); i++) {
    cout << "Haloween Tree Shipments " << i + 1 << std::endl;
    cout << "Total Weight: " << HT[i].calculatetotalweight() << std::endl;
    cout << "Total Price: " << HT[i].calculatetotalprice() << std::endl;
    cout << "Total Volume: " << HT[i].calculatethevolume_of_one_tree()
         << std::endl;
    cout << "Total Area: " << HT[i].calculatethearea_of_one_tree() << std::endl;

    grandtotalweight += HT[i].calculatetotalweight();
    grandtotalprice += HT[i].calculatetotalprice();
    grandtotalvolume += HT[i].calculatethevolume_of_one_tree();
    grandtotalarea += HT[i].calculatethearea_of_one_tree();
  }
  cout << "\nGRAND TOTALS FOR HALOWEEN TREES" << endl;
  cout << "Grand Total Weight: " << grandtotalweight << endl;
  cout << "Grand Total Price: " << grandtotalprice << endl;
  cout << "Grand Total Volume: " << grandtotalvolume << endl;
  cout << "Grand Total Area: " << grandtotalarea << endl;

  cout << "\nGRAND TOTALS FOR ALL TREES" << endl;
  cout << "Grand Total Weight: " << grandtotalweight << endl;
  cout << "Grand Total Price: " << grandtotalprice << endl;
  cout << "Grand Total Volume: " << grandtotalvolume << endl;
  cout << "Grand Total Area: " << grandtotalarea << endl;
};