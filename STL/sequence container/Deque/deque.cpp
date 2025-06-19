#include <iostream>
#include <deque>

// Deque stands for double Ended Queue
// A deque stores elements in multiple smaller blocks, not all in one place:
// is a data structure that lets you add and remove elements from both the 
// front and the back, unlike a normal queue that only allows removal from the front.

// Faster than vector for front insertions/removals (doesn't require shifting elements).
// Faster than list for random access (you can use dq[i] like an array).
// Works as both a queue and a stack, making it flexible.

// If you insert or delete elements in the middle of a deque, it is slow (O(N)), just like a vector.

int main() {

  std::deque<int> deq = {5, 6, 7, 8};

  deq.push_front(67);
  deq.push_back(87);

  deq.emplace_front(100);
  deq.emplace_back(100);

  deq.pop_back();
  deq.pop_front();

 deq.insert(deq.begin() + 2, 5);

  for(int element : deq) {
    std::cout << element << " ";
  }
  std::cout << '\n';

  std::cout << deq[2] << '\n'; // can access any element directly

  // Use deque when you need fast insertions and deletions at both ends!

  // If you need fast middle insertions/deletions, use list (O(1)).
  // 👉 If you need fast random access, use deque or vector.

  //Structure 	Memory Layout	            Random Access 	                          Insertion/Deletion at Front
  //vector  	  Single contiguous block   ✅ Very Fast (O(1)) 	                    ❌ Slow (O(N))
  //deque	      Multiple memory blocks    ✅ Fast (O(1), but slower than vector)   ✅ Fast (O(1))


  return 0;
}