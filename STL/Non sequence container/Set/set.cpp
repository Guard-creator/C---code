#include <iostream>
#include <set>

// A set in C++ is a container that stores unique elements in sorted (ascending) order by default.

// No duplicates allowed
// Automatically sorted
// Backed by a balanced binary search tree (usually a Red-Black Tree)
// Fast lookup, insertion, and deletion: O(log n)

int main() {

  std::set<int> s;

  s.insert(2);
  s.insert(4);
  s.insert(6);
  s.insert(21);
  s.insert(75);
  s.insert(2); // no duplicates already exist
  s.insert(22);

  for(int pr : s) {
    std::cout << pr << " ";
  }

  std::cout << '\n';
  std::cout << s.size() << '\n'; // size remain same 

  return 0;
}