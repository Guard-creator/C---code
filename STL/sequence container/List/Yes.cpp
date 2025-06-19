#include <iostream>
#include <list>

int main() {

  
  // in list finding the element is slow 
  // this is not possible
  // std::list<int> lis = {5, 7, 8};
  // std::cout << *lis.begin() + 2;

  // instead we use advance funtion 

  // Finding index 1 (second element) is slow (O(n)):
  std::list<int> name = {8, 5, 7};
  auto it = name.begin(); // point to first element.
  advance(it, 1);
  for(int element : name) {
    std::cout << element << " ";
  }
  std::cout << '\n';
  std::cout << *it << '\n';

  // In a list, you cannot access elements using list[i] like you do with vector[i]. 
  // Instead, you must use an iterator to move step by step.
  // The advance(it, n) function moves an iterator it forward by n positions.
  // It works for all STL containers that use iterators (list, vector, set, etc.).

  // inserting in the middle is fast (O(1))

  std::list<int> love = {1, 2, 3, 4};
  
  auto it2 = love.begin();
  advance(it2, 2);
  love.insert(it2, 100);
  for(int element : love) {
    std::cout << element << " ";
  }

  // advance is like it move iterator to the next which value is assigned.
 
  return 0;
}