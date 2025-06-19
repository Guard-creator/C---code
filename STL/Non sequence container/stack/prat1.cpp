#include <iostream>
#include <stack>

int main() {

  std::string input;
  std::cout << "Enter Anything And we Reverse it: ";
  std::getline(std::cin, input);

  std::stack<char> ss;
  for(char chr : input) {
    ss.push(chr);
  }

  while(!ss.empty()) {
    std::cout << ss.top();
    ss.pop();
  }

  return 0;
}