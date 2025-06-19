#include <iostream>
#include <map>
#include <vector>

int main() {

  // using map to check how many times a number may appear in arr.

  std::vector<int> numbers = {1, 1, 2, 3, 3, 4, 5, 6, 3, 7, 8};

  std::map<int, int> freq;

  for(int num : numbers) {
    freq[num]++;
  }

  for(auto pair : freq) {
    std::cout << "This Number " << pair.first << " Appear " << pair.second << " Times\n";
  }

  // string example down below enter a string

  std::cout << "++++++++++++++++++++++++++++++++++\n";
  
  std::string text;
  std::cout << "Enter a word: ";
  std::getline(std::cin, text);
  
  std::map<char, int> map;

  for(char ch : text) {
    map[ch]++;
  }

  for(auto m : map) {
    std::cout << m.first << " Appear " << m.second << " Times. \n";
  }

}