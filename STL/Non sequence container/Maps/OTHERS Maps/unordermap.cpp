#include <iostream>
#include <unordered_map>

// An unordered_map is an associative container that stores key-value pairs 
// in no specific order and does not allow duplicate keys. It uses a hash table internally, 
// providing average-case O(1) time complexity for insertions and lookups.

// Unordered (no sorting)
// No duplicate keys
// Uses a hash table
// Very fast → O(1) on average
// 🧠 Use for fast lookups when order doesn’t matter.

int main() {

  std::unordered_map<std::string, int> unmap;

  unmap.insert({"Gamber", 32});
  unmap.insert({"razer", 321});
  unmap.insert({"reddragon", 3222});
  unmap.insert({"public", 3256});
  unmap.insert({"comprehensive", 6754});
  unmap.insert({"abc", 9999});
  unmap.insert({"zzz", 1});
  unmap.insert({"hello", 6000});
  unmap.insert({"map", 5555});

  for(auto pr : unmap) {
    std::cout << pr.first << ": " << pr.second << '\n';
  }

  return 0;
}