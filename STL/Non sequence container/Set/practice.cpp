#include <iostream>
#include <sstream>
#include <set>

int main() {

  int count;
  std::string input;

  std::cout << "Enter a Sentence: ";
  std::getline(std::cin, input);
  std::stringstream ss(input);

  std::string word;

  std::set<std::string> s;

  while(ss >> word) {
    s.insert(word);
  }

  std::cout << s.size() << " unique words are here.\n";


  return 0;
}