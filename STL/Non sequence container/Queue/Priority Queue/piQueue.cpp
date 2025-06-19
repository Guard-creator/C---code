#include <iostream>
#include <queue>

// A priority queue is a special type of queue in which each element is associated with a 
// priority, and elements are served based on their priority rather than just their order in the queue.

// - Higher priority elements are dequeued before lower priority ones.
// - If two elements have the same priority, they are served according to their 
//   order in the queue (FIFO for equal priorities).

int main() {

  // soo here
  // elements in queue are sorted with least priority
  // so top one will be with least element in whole queue

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;

  //✅ int
  //  This tells the queue that you're storing integers.
  //✅ std::vector<int>
  //  This is the underlying container used to store the elements.
  //  you can change which ever container you like deque but vector is universal options
  //✅ std::greater<int>
  //  This is the comparison function that decides how priorities are compared.

  q.push(5);
  q.push(7);
  q.push(3);
  q.push(10);
  q.push(44);

  std::cout << "Least Priority Queue: ";
  while(!q.empty()) {
    std::cout << q.top() << " ";
    q.pop();
  };
  std::cout << '\n';

  // AND ---------------------

  // here
  // elements are sorted with highest priority 
  // so top one Will be the one with highest priority in whole queue

  std::priority_queue<int> q2;

  // by default it use std::least<int>
  // By default, priority_queue uses a vector to store items internally

  q2.push(42);
  q2.push(56);
  q2.push(4);
  q2.push(2);
  q2.push(42);
  q2.push(56);

  std::cout << "Highest Priority Queue: ";
  while(!q2.empty()) {
    std::cout << q2.top() << " ";
    q2.pop();
  }

  return 0;
}