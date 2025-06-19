#include <iostream>
#include <vector>
#include <map>

int main() {

  std::vector<std::string, int> vec = { {"Ali", 90}, {"Sara", 85}, {"Usman", 90}, {"Zain", 75} };
  std::multimap<int, std::string> map;

  for(auto pr : vec) {
    map[pr]++;
  }

  for(auto pr : map) {
    std::cout << pr.first << " Appeared " << pr.second << " Times.\n";
  }

  return 0;
}