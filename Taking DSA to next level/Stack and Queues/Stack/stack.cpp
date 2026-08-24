#include <iostream>

// Stack (Last in first out)
// we study this in stl so ik what is this
// we implement rn

// we implement this using array
// we use single variable to manipulate stack
// when we store something in array and pop up 
// we just move the topIndex backwards to remove it
// in reality that we value is still in array 
// and we dont need to remove it if we want to store 
// something new it will just overwrite it

class Stack {

  int arr[1000];
  int topIndex;

  public:

    Stack() : topIndex(-1) {}

    void push(int val) {
      if(topIndex >= 999) {
        std::cout << "Stack Overflow.\n";
        return;
      }
      arr[++topIndex] = val;
    }

    void pop() {
      if(topIndex < 1) {
        std::cout << "Stack Underflow.\n";
        return;
      }
      topIndex--; // move back to remove it
    }

    bool isEmpty() {
      return topIndex < 0;
    }

    int size() {
      return topIndex + 1;
    }

    int top() {
      if(topIndex < 0) {
        std::cout << "Stack is Empty.\n";
        return -1;
      }
      return arr[topIndex];
    }

    void display() {
      if(topIndex < 0) {
        std::cout << "Stack is Empty.\n";
        return;
      }
      // because it's stack
      for(int i = topIndex; i >= 0; i--) {
        std::cout << arr[i] << " ";
      }
      std::cout << '\n';
    }

};

int main() {

  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(69);

  s.display();

  std::cout << "Size: " << s.size() << '\n';
  std::cout << "Top: " << s.top() << '\n';
  std::cout << "if Empty: " << s.isEmpty() << '\n';

  s.pop();
  s.pop();
  s.display();

  return 0;
}