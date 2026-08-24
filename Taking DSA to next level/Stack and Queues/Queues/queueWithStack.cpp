#include <iostream>
#include <stack>

// implement Queue with stack

// we use two stack

// we push normally in first stack but when popping
// we will first reverse the order and shift to second stack
// so it's top it's Queue front 
// and we can pop then

class QueueMe {

  std::stack<int> st1;
  std::stack<int> st2;

  public:

    void enqueue(int val) {
      
      while(!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
      st1.push(val);
      while(!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
      }

    }

    void dequeue() {
      st1.pop();
    }

    int peek() {
      return st1.top();
    }

    bool empty() {
      return st1.empty();
    }

    void display() {

      std::stack<int> temp = st1;
      while(!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop(); 
      }
      std::cout << '\n';

    }

};


class Queue {

  std::stack<int> st1;
  std::stack<int> st2;

public:

  Queue() {}

  void enqueue(int val) {
    st1.push(val);
  }

  int dequeue() {
    peek(); // reverse order
    int val = st2.top();
    st2.pop();
    return val;
  }

  int peek() {

    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }
    return st2.top();
  }

  bool empty() {
    return st1.empty() && st2.empty();
  }

  void display() {

    std::stack<int> temp1 = st1;
    std::stack<int> temp2 = st2;

    std::stack<int> tempFront = temp2;
    while(!tempFront.empty()) {
      std::cout << tempFront.top() << " ";
      tempFront.pop();
    }

    std::stack<int> rev;
    while(!temp1.empty()) {
      rev.push(temp1.top());
      temp1.pop();
    }
    while(!rev.empty()) {
      std::cout << rev.top() << " ";
      rev.pop();
    }
    std::cout << '\n';

  }

};


int main() {

  Queue qu;

  qu.enqueue(10);
    qu.enqueue(20);
      qu.enqueue(30);

      qu.dequeue();

      qu.display();

  return 0;
}