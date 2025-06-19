#include <iostream>
#include <deque>

bool isPlindrome(std::string word) {

  std::deque<char> dq(word.begin(), word.end());

  while(dq.size() > 1) {
    if(dq.front() != dq.back()) {
      return false;
    }
    dq.pop_back();
    dq.pop_front();
  }
  return true;
 
}

int main() {

  std::string word;
  std::cout << "Enter a Word: ";
  std::getline(std::cin, word);

  if(isPlindrome(word)) {
    std::cout << "This is Plindrome\n";
  } else {
    std::cout << "This is Not Plindrome\n";
  }

  return 0;
}