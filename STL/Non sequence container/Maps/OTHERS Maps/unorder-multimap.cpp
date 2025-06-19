#include <iostream>
#include <unordered_map>

// unordered_multimap is an unordered associative container that allows multiple pairs 
// with the same key, and stores them using a hash table.

// Use unordered_multimap when:
// You want fast insertions and lookups
// You expect duplicate keys
// You don’t care about order

int main() {

  std::unordered_multimap<std::string, int> UnMm;

  UnMm.insert({"Yk", 12});
  UnMm.insert({"Iam", 1342});
  UnMm.insert({"Yk", 12});
  UnMm.insert({"Trust", 34});
  UnMm.insert({"lies", 2334});

  for(auto pr : UnMm) {
    std::cout << pr.first << ": " << pr.second << '\n';
  }

  return 0;
}