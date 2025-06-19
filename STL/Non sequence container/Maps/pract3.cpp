#include <iostream>
#include <map>

int main() {

  std::map<std::string, int> map1 = {{"apple", 3}, {"banana", 4}};
  std::map<std::string, int> map2 = {{"banana", 3}, {"grapes", 4}};

  for(auto pr : map2) {
    map1[pr.first] += pr.second;
  }

  for(auto pr : map1) {
    std::cout << pr.first << ": " << pr.second << '\n';
  }

  return 0;
}