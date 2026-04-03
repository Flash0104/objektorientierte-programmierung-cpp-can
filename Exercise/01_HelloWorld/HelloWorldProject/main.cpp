#include <iostream>
#include <string>
using namespace std;

int main() {
  string name, surname;
  cout << "What is your name? ";
  getline(cin, name);
  cout << "What is your surname? ";
  getline(cin, surname);
  cout << "Hello " << name << " " << surname << "!" << endl;
  return 0;
}
