#include <iostream>
#include <map>

// A multimap is similar to map, but it allows duplicate keys. It stores 
// all elements in sorted order by key and uses a red-black tree internally. 
// Each operation takes O(log n) time.

// - Like std::map, but allows duplicate keys.
// - Also ordered.
// - Internally uses a balanced BST like map.

int main() {

  std::multimap<std::string, int> mm;

  mm.insert({"Amber", 102});
  mm.insert({"Amber", 102});
  mm.insert({"Amber", 102});
  mm.insert({"Amber", 102});
  mm.insert({"Amber", 102});
  
  for(auto pr : mm) {
    std::cout <<  pr.first << ": " << pr.second << '\n';
  }

  return 0;
}