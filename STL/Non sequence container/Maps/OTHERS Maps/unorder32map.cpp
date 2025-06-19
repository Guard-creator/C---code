#include <iostream>
#include <sstream>
#include <unordered_map>

int main() {

  std::string input = "hello world";
  std::string word;

  std::unordered_map<char, int> unMap;
  std::stringstream ss(input);

  while(ss >> word) {
    for(char w : word) {
      unMap[w]++;
    }
  }

  for(auto pr : unMap) {
    std::cout << pr.first << ": Appeared " << pr.second << " Times.\n"; 
  }


  return 0;
}