#include <iostream>
#include <unordered_map>

bool checkAnagram(const std::string& a, const std::string& b) {

  if(a.length() != b.length()) return false;

  std::unordered_map<char, int> unMap;

  for(char ch : a) {
    unMap[ch]++;
  }

  for(char ch : b) {
    unMap[ch]--;
  }

  for(auto pair : unMap) {
    if(pair.second != 0) return false;
  }

  return true;
};

int main() {

  std::string intputA, intputB;
  std::cout << "Enter InputA: ";
  std::getline(std::cin, intputA);
  std::cout << "Enter InputB: ";
  std::getline(std::cin, intputB);

  if(checkAnagram(intputA, intputB)) {
    std::cout << "Yes its Anagram";
  } else {
    std::cout << "Na its not Anagram";
  }

  return 0;
}