#include <iostream>

// An Circular Queue 
// it's sing FIFO(first in, first out)
// but at the back of queue it's doesn't end
// it goes back to front of queue 
// if the rear reach it's end and front index is empty 
// 0, 0, 3, 4
// then insert at the front index

// Explaining
// Circular Should have an fix size otherwise how it will be circular 
// and an currentSize that will track how many time have we insert at arr
// and track size
// we use (nth + 1) % size
// on front and rear 
// it will give the value btw the 0 and size
// so if we reach the end and front is empty 
// we can easily insert at front

class CircularQueue {

  int front, rear;
  int crrSize = 0;
  int arr[5];
  int size = sizeof(arr) / sizeof(arr[0]);

  public:

    CircularQueue() : front(0), rear(-1) {};

    void enqueue(int val) {
      if(crrSize == size) {
        std::cout << "Queue is Full.\n";
        return;
      }

      rear = (rear + 1) % size;
      arr[rear] = val;
      crrSize++;
    }

    int dequeue() {
      if(crrSize == 0) {
        std::cout << "Queue is Empty.\n";
        return -1;
      }

      int deq = arr[front];
      front = (front + 1) % size;
      crrSize--;
      return deq;
    }

    int peek() {
      if(crrSize == 0) {
        std::cout << "Queue is Empty.\n";
        return -1;
      }

      return arr[front];
    }

    bool isEmpty() {
      return crrSize == 0;
    }

    void display() {
      if(crrSize == 0) {
        std::cout << "Queue is Empty.\n";
        return;
      }

      int tempSize = crrSize;
      int tempFront = front;
      while(tempSize--) {
        std::cout << arr[tempFront] << " ";
        tempFront = (tempFront + 1) % size;
      }
      std::cout << '\n';

    }

};


int main() {

  CircularQueue qu;

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);

    std::cout << "Dequeue: " << qu.dequeue() << '\n';
    std::cout << "Dequeue: " << qu.dequeue() << '\n';
    std::cout << "Peek: " << qu.peek() << '\n';
    std::cout << "IsEmpty: " << qu.isEmpty() << '\n';

    qu.display();


  return 0;
}