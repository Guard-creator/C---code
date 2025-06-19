#include <iostream>
#include <list>

// A list is similar to a vector in that it can store multiple elements of the 
// same type and dynamically grow in size.
// However, two major differences between lists and vectors are:

//- You can add and remove elements from both the beginning and at the end of a list, 
// while vectors are generally optimized for adding and removing at the end.

//- Unlike vectors, a list does not support random access, meaning you cannot directly jump to a 
// specific index, or access elements by index numbers.

// idk what that is but..
// it behaves like a doubly linked list

// When you need to insert/delete elements in the middle frequently (e.g., playlist management).

int main() {

  std::list<int> lis = {4, 8, 9};

  lis.push_back(10);
  lis.push_front(20);

  lis.emplace_back(10);
  lis.emplace_front(20);
  
  lis.push_back(90);
  lis.push_front(100);

  lis.pop_back();
  lis.pop_front();

  for(int element : lis) {
    std::cout << element << " ";
  }

  std::cout << '\n';
  std::cout << '\n';

  for(auto it = lis.begin(); it != lis.end(); it++) {
    std::cout << *it << "  ";
   }

  return 0;
}