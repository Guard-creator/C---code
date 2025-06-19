#include <iostream>

int main() {

  // null pointer are those pointer that are not assigned pointer
  
  // it is useful when we want to check if the pointers are 
  // successfully assigned to the pointer.

  // when using pointers, we have to be careful that the pointer
  // should not be null when working or pointing to free memory
  // that will cause undefined behavior. 

  int * pointer = nullptr;
  int x = 112;

  pointer = &x;

  if(pointer == nullptr) {
    std::cout << "Pointer is Not Assigned";
    //std::cout << *pointer;
    // this is very dangerous when you try to defrence the pointer 
    // it will crash the whole program
    // it is illegal in c++ to do this 
    // that why we have to check if the pointer is null or not.
  } else {
    std::cout << "Pointer was Assigned";
  }

  delete pointer;

  return 0;
}