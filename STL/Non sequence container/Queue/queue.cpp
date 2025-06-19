#include <iostream>
#include <queue>

// A queue stores multiple elements in a specific order, called FIFO.

// FIFO stands for First in, First Out. To visualize FIFO, think of a queue as people standing 
// in line in a supermarket. The first person to stand in line is also the first who can pay and leave 
// the supermarket. This way of organizing elements is called FIFO in computer science and programming.

// Unlike vectors, elements in the queue are not accessed by index numbers. Since queue elements are added at 
// the end and removed from the front, you can only access an element at the front or the back.

// 🔹 Example Use Case:
// Queues are used in:
// Job scheduling
// Print queues
// Level-order traversal in trees
// Breadth-first search (BFS) in graphs

int main() {

  std::queue<int> q;

  q.push(54);
  q.push(423);
  q.push(42);

  std::cout << "Front: " << q.front() << '\n';
  std::cout << "Back: " << q.back() << '\n';

  q.pop();

  std::cout << "Front After Back: " << q.front() << '\n';

  return 0;
}