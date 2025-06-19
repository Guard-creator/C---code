#include <iostream>
#include <stack>

// If the stack is empty, or val is greater than the top element: → ✅ Just push(val).
// Otherwise (val is smaller than top element): → ❌ We can’t put it on top right now. → So:
// We pop the top
// Call insertSorted() again with the remaining stack
// Then push the top back
// This creates space for val to go in the correct position.

void insertSorted(std::stack<int>& s, int val) {
  if(s.empty() || val > s.top()) {
    s.push(val);
    return;
  }

  int top = s.top();
  s.pop();
  insertSorted(s, val);
  s.push(top);
}
// It puts val back into the stack at the right position so that everything stays sorted.

// Example
// Stack (sorted): [1, 3, 5] (top = 5)
// Insert 4:
// 4 < 5 → Pop 5, recurse.
// 4 > 3 → Push 4.
// Push 5 back.
// Result: [1, 3, 4, 5].

void sortStack(std::stack<int>& s) {
  if(s.empty()) return;

  int top = s.top();
  s.pop();
  sortStack(s);
  insertSorted(s, top);
}

// It removes everything from the stack one by one using recursion.
// When the stack is empty, it starts to insert the items back in sorted order using insertSorted.

int main() {

  std::stack<int> s;
  s.push(3);
  s.push(5);
  s.push(4);
  s.push(2);
  s.push(1);

  sortStack(s);

  std::cout << "Sorted stack: ";
  while(!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }

  return 0;
}