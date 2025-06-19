#include <iostream>
#include <vector>
#include <stack>

// A stack is a data structure that works on the Last In, First Out (LIFO) principle. 
// This means the last item added (or "pushed") to the stack is the first one removed 
// (or "popped").

// function are same 
// peek / top	View the top element without removing it
// but a new funtion is here to remove or check

// Unlike vectors, elements in the stack are not accessed by index numbers. 
// Since elements are added and removed from the top, you can only access the 
// element at the top of the stack.

int main() {

  // You have to first initialize the underlying container (like a vector or deque) 
  // and then pass it to the stack constructor.
  // you cant directly initialize stack with values.

  std::vector<int> vec = {45, 6, 7, 8};

  std::stack<int, std::vector<int>> stk(vec);
  // int: This is the type of elements the stack will store.
  // std::vector<int>: This is the underlying container the stack will use 
  // internally to store those elements.
  // So, you're telling the compiler:
  // "Hey, I want a stack of ints, and I want it to use a std::vector<int> underneath."

  stk.push(78);
  std::cout << stk.top() << '\n';
  stk.push(6);
  std::cout << stk.top() << '\n';
  stk.pop();
  std::cout << stk.top() << '\n';

  // Stacks are also used as a base to build more complex data structures

  return 0;
}