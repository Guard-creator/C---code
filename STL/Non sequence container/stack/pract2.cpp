#include <iostream>
#include <stack>

bool isBalance(std::string input) {
  std::stack<char> s;

  for(char chr : input) {

    if(chr == '(' || chr == '{' || chr == '[') {
      s.push(chr);
    } else if (chr == ')' || chr == '}' || chr == ']') {
        if(s.empty()) return false;
        // \|/ If there's no opening bracket in the stack to match —
        //  |  return false immediately.

        char top = s.top();
        if((chr == ')' && top != '(') ||
           (chr == '}' && top != '{') ||
           (chr == ']' && top != '[')) {
            return false;
        }
        s.pop();
      }
  }
  return s.empty();
  // If the stack is empty → all opening brackets had a matching close → balanced ✅
  // If not → some brackets didn’t get matched → not balanced ❌
}

int main() {

  std::string input = "{[(a+b)*c]}";
  std::cout << (isBalance(input) ? "Balance" : "Not Balance") << '\n';

  return 0;
}