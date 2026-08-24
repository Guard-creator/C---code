#include <iostream>

// Queue.....

// A Queue is a linear data structure that stores elements in a sequence 
// but unlike a stack (which is LIFO),
// a queue follows the FIFO rule:
// First In, First Out
// That means — the element that enters first, leaves first.

// we implement Queue using array 
// Litearlly your bro is getting better 
// on first try

// i initailly set rear to -1 
// becasue when u insert a value the index should at 0
// and front is initailly zero (My way btw :)..)
// because if i enqueue i also have to set front to zero 
// with statement use 
// soo i think i should just directly set it to zero 
// and if we dequeue when queue is empty 
// i already set the statement 
// we can also statement there but this is how i do it 

class Queue {

  int arr[100];
  int front;
  int rear;

  public:

    Queue() : rear(-1), front(0){}

    void enqueue(int val) {
      if(rear >= 99) {
        std::cout << "Queue is Overflow.\n";
        return;
      }
      arr[++rear] = val;
    }

    int dequeue() {
      if(front > rear) {
        std::cout << "Queue is Underflow.\n";
        return -1;
      }
      int val = arr[front++];
      return val;
    }

    int peek() {
      return arr[front];
    }

    bool isEmpty() {
      return (rear < front);
    }

    void display() {
      if(rear < front) {
        std::cout << "No Values to display.\n";
        return;
      }
      std::cout << "Queue: ";
      for(int i = front; i <= rear; i++) {
        std::cout << arr[i] << " ";
      }
      std::cout << '\n';
    }

};

int main() {

  Queue qu;

  qu.enqueue(10);
    qu.enqueue(20);
      qu.enqueue(30);
        qu.enqueue(40);

  qu.display();

  std::cout << "Dequeue: " << qu.dequeue() << '\n'; 
  std::string isEmpty = (qu.isEmpty()) ? "True" : "False";
  std::cout << "IsEmpty: " << isEmpty << '\n';
  std::cout << "Peek: " << qu.peek() << '\n';

  qu.display();

  return 0; 
}
