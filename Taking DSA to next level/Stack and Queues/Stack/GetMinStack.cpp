#include <iostream>
#include <stack>

// Min Stack (LeetCode 155)
// You need to design a stack but with an extra feature:
// besides normal push, pop, and top, it must also support a function getMin() 
// that returns the minimum element in the stack in O(1) time.

// now u can use brute force to find the min but it will O(n) 
// we need O(1).

// to solve this 
// we need to use two stacks to store all number and for Minimum Numbers
// basically when we push 
// we push at first stack Normally 
// in Minimum we check if it's empty or The value we are inserting is less then 
// the top value in min stack (only then Insert the value)
// this way the Values in minimum will always be at top in MinStack

class Stack {
  public:

    std::stack<int> st;
    std::stack<int> minSt;

    Stack(){}

    void push(int val) {
      // push here normally
      st.push(val);

      // check if empty or less then
      // only then push in minst
      if(minSt.empty() || val <= minSt.top()) {
        minSt.push(val);
      }
    }

    void pop() {
      // Only remove from minSt when the value is same as in first stack st
      // because this way we can keep the minimum values 
      // because when we push values 5, 3, 7 and min st will have 5, 3 
      // so when we pop from both side we will be losing three
      // that why we check before poping
      // only if equal then pop from min st
      // otherwise value in st will be bigger(not minimum)
      if(st.top() == minSt.top()) {
        minSt.pop();
      }

      st.pop();
    }


    int top() {
      return st.top();
    }

    int getMin() {
      // just simply return minst on top 
      // it will always be minimum 
      // because the way we insert the values 
      return minSt.top();      
    }

};

int main() {

  Stack s;

  s.push(1);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(69);
  s.pop();
  s.pop();

  std::cout << "Top: " << s.top() << '\n';

  std::cout << "Minimum: " << s.getMin() << '\n';

  return 0;
}