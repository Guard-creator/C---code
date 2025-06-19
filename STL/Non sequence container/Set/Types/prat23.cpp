#include <iostream>
#include <unordered_set>
#include <vector>

int main() {

  std::vector<std::string> vec = {"Alice", "Bob", "Alice", "Eve", "Bob"};

  std::unordered_set<std::string> uniqueName;

  for(auto pr : vec) {
    if(uniqueName.find(pr) == uniqueName.end()) {
      uniqueName.insert(pr);
    }
  }

  for(auto name : uniqueName) {
    std::cout << name << ", ";
  }

  return 0;
}