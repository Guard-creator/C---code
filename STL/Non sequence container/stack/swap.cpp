#include <iostream>
#include <stack>

  // we can also swap stack using swap() funtion

int main() {

  std::stack<int> s1;

  s1.push(23);
  s1.push(76);
  s1.push(63);

  std::stack<int> s2;

  s2.push(667);

  std::cout << "Before s1 size: " << s1.size() << '\n'; 
  std::cout << "Before s2 size: " << s2.size() << '\n'; 

  s1.swap(s2);

  std::cout << "After s1 size: " << s1.size() << '\n'; 
  std::cout << "After s2 size: " << s2.size() << '\n'; 

  return 0;
}