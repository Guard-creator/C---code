#include <iostream>
#include <set>
#include <unordered_set>

  // A multiset is an associative container that stores elements in sorted order, 
  // just like set, but allows duplicate elements.

  // Elements are always automatically sorted.
  // Duplicates are allowed (unlike set).
  // Elements are immutable (you cannot modify them directly).
  // insert, delete all take O(log n) time.

int main() {

  std::multiset<int> ms = {1, 2, 3, 1, 2, 5, 6, 23, 8};

  for(int pr : ms) {
    std::cout << pr << " ";
  }

  std::cout << '\n';

  // An unordered_set is an associative container that stores unique elements, 
  // but the order is not guaranteed. It uses a hash table internally for fast access.

  // No duplicates allowed (like set).
  // Order is not sorted (random).
  // Operations (insert, find, erase) are on average O(1) time.
  // But worst-case time can be O(n) if hash collisions occur.

  std::unordered_set<std::string> us = {"apple", "banana", "apple", "orange"};
  
  for(auto pr : us) {
    std::cout << pr << ", ";
  }

  std::cout << '\n';

  return 0;
}