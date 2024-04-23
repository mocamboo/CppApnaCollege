#include <iostream>
#include <ostream>
using namespace std;

class Box {
public:
  int length;
  Box() : length(10) {}
};

int main() {
  Box sq;              // Stack allocation
  Box *rt = new Box(); // Dynamic Allocation (Heap Allocation)
  cout << sq.length << endl;
  return 0;
}