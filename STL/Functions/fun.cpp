#include <iostream>
#include <vector>

// this function is called iterators
// we use tis function to loop in vector

// two more function of end and  Begin
// are like pointer 
// begin point to first element of vector
// end point dont point to the last element of vector
// but it point to the after the last element vector which its capacity 
// and also a garbage value, it return zero

int main() {

  std::vector<int> vec = {5, 4, 3, 7, 8};

  // vec.begin() get the memory address of vector of first element
  // vec.end() get the garbage value 
  // it gives only memory address so we use * dereference to get the value 

  /*
    std::cout << *vec.begin() << '\n'; 
    std::cout << *vec.end() << '\n';
  */

  // another function about it is that erase
  vec.erase(vec.begin() + 1);
  // remember here its decrease the size but not capacity.

  for(int element : vec) {
    std::cout << element << " ";
  }
  std::cout << '\n';
  std::cout << "Vector Size: " << vec.size() << '\n'; // one elemen is erase, size become 4
  std::cout << "Vector Capacity: " << vec.capacity() << '\n'; // its orginal capacity is 5

  // here how to insert a element in vector

  std::cout << '\n';
  std::cout << '\n';

  std::vector<int> vec1 = {1, 2, 3, 45};

  vec1.insert(vec1.begin() + 2, 5);
  
  for(int element : vec1) {
    std::cout << element << " ";
  }

  return 0;
}