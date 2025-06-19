#include <iostream>

class Queue {

  private:

    int rear, front, size;
    int* arr;

  public:

    Queue(int n) {
      size = n;
      front = 0;
      rear = -1;
      arr = new int[size];
    }

    void enqueue(int x) {
      if(rear == size - 1) {
        std::cout << "Queue is overflow, Cannot Add.\n";
        return;
      };

      arr[++rear] = x;
      std::cout << "Enqueue: " << x << '\n';
    };

    void dequeue() {
      if(isEmpty()) {
        std::cout << "Queue is underflow, nothing to remove.\n";
        return;
      }
      std::cout << "Dequeue: " << arr[front++] << '\n';
    }; 

    bool isEmpty() {
      return front > rear;
    }

    int peek() {
      if(isEmpty()) {
        std::cout << "Queue is Empty.\n";
        return -1;
      }; 
      return arr[front];
    }

    void printQueue() {
      if(isEmpty()) {
        std::cout << "Queue is Empty.\n";
        return;
      }

      std::cout << "Queue: ";
      for(int i = front; i <= rear; i++) {
        std::cout << arr[i] << " ";
      } 
    };
  
};

int main() {

  Queue q(3);

  q.enqueue(45);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(32);

  q.dequeue();

  q.printQueue();

  return 0;
};