#include <iostream>
#include <memory>

// to use smart pointer we include <memory>

// Smart pointers in C++ are objects that manage dynamic memory automatically, 
// helping to prevent memory leaks and dangling pointers. They are part of the 
// C++ Standard Library and handle the allocation and deallocation of memory 
// automatically when they go out of scope

// its simply automatically do "new" & "delete" in smart pointer

// there are three types of pointers

// std::unique_ptr 

// Only one unique_ptr can own a resource at a time.
// Automatically deletes the resource when it goes out of scope.
// Cannot be copied, but can be moved to transfer ownership.

class Animal {

  public:

  Animal() {
    std::cout << "Animal is Created" << '\n';
  }

  // this is called destuctor 
  // this function get called whenever the object is created in the end
  ~Animal() {
    std::cout << "Animal Got Kill";
  }

  // the destructor got executed in the end because 
  // we create the object in main function
  // and when the main function ends 
  // unique pointer get out of scope 
  // and executed the destructor.

};

int main() {

  // again it cannot be copied you can tranfer ownership only 
  // means where you transfer in the second pointer will only 
  // hold that value not the first pointer on..

  std::unique_ptr<Animal> ptr1 = std::make_unique<Animal>();
  // we cant copy the ptr but we can transfer the owner ship to 
  // the othe pointer like here 
  // like this we can copy here
  //  std::unique_ptr<Animal> ptr2 = ptr1;
  std::unique_ptr<Animal> ptr2 = std::move(ptr1);

  if(!ptr1) {
    std::cout << "Yes brotha you Right!\n";
  }

  return 0;
}