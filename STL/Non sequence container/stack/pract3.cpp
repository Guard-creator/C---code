#include <iostream>
#include <stack>
#include <cctype>

int expressionPostFix(std::string expr) {

  std::stack<int> s;

  for(char ch : expr) {
    if(isdigit(ch)) {
      s.push(ch - '0');
    } else {
      int b = s.top(); s.pop();
      int a = s.top(); s.pop();
      switch (ch) {
        case '+' : s.push(a + b); break;
        case '-' : s.push(a - b); break;
        case '*' : s.push(a * b); break;
        case '/' : s.push(a / b); break;
      }
    }
  }

  return s.top();
}



int main() {

  std::string expr = "23*54*+9-";
  std::cout << expressionPostFix(expr) << '\n';

  return 0;
}
