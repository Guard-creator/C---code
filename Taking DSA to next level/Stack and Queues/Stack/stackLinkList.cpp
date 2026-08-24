#include <iostream>

// this is the implementation of Stack using linkedList
// easy not give much thought

class Node {

  public:

    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {};

};

class Stack {

  Node* topNode;

  public:

    Stack() : topNode(NULL) {}

    void push(int val) {
      Node* newNode = new Node(val);
      newNode->next = topNode;
      topNode = newNode;
    }

    void pop() {
      if(!topNode) return;
      Node* temp = topNode;
      topNode = topNode->next;
      delete temp;
    }

    int top() {
      if(!topNode) return -1;
      return topNode->data;
    }

    int size() {
      int count = 0;
      Node* temp = topNode;
      while(temp != NULL) {
        temp = temp->next;
        count++;
      }
      return count;
    }

    bool isEmpty() {
      return !topNode;
    }

    void display() {
      if(!topNode) return;
      Node* temp = topNode;
      while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << std::endl;
    }

};

int main() {

  Stack s;

  s.push(1);
  s.push(2);
  s.push(3);

  s.display();

  std::cout << "Size: " << s.size() << '\n';
  std::cout << "Top: " << s.top() << '\n';
  std::cout << "Empty Or not: " << s.isEmpty() << '\n';

  s.pop();
  s.display();

  return 0;
}