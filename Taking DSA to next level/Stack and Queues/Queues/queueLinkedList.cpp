#include <iostream>

// Implementing Queue Using Linked List
// it's was kinda easy 

struct Node{
  int data;
  Node* next;
    Node(int val) {
      data = val;
      next = NULL;
    }
};

class Queue {

  // need Two pointer for front and Back to implement Queue
  Node* front;
  Node* rear;

  public:

    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int val) {
      if(front == NULL && rear == NULL) {
        Node* newNode = new Node(val);
        front = rear = newNode;
        return;
      }
      Node* newNode = new Node(val);
      // Link the last node (rear) to the new node
      // rear->next was NULL before, now points to the new node
      // Move the rear pointer to the newly added node
      // (so rear always points to the last node in the queue)
      rear->next = newNode;
      rear = newNode;
    }

    int dequeue() {
      Node* temp = front;
      int val = temp->data;
      front = front->next;
      if(front == NULL) rear = NULL;
      delete temp;
      return val;
    }

    int peek() {
      if(front == NULL) {
        std::cout << "Queue is Empty.\n";
        return 0;
      }
      return front->data;
    }

    bool isEmpty() {
      return front == NULL;
    }

    void display() {
      if(!front) return;
      Node* temp = front;
      std::cout << "Queue: "; 
      while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
      }
      std::cout << std::endl;
    }

};

int main() {

  Queue qu;

  qu.enqueue(10);
  qu.enqueue(20);
  qu.enqueue(30);
  qu.enqueue(40);
  
  std::cout << "Dequeue: " << qu.dequeue() << '\n';
  std::cout << "Peek: " << qu.peek() << '\n';
  std::string isEmpty = qu.isEmpty() ? "True" : "false";
  std::cout << isEmpty << '\n';

  qu.display();

  return 0;
}