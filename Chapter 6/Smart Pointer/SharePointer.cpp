#include <iostream>
#include <memory>

// this is smart pointer repating we dont have to specify 
// new and del it's automatically do that 
// that why its smartpointer

// Another type of smart pointer are 
// std::shared_ptr

// in this pointer you can share ownership of the pointer 
// or takes it's ownership directly 

// Ownership: Shared ownership of the resource. Multiple shared_ptr 
// instances can point to the same object.
// Usage: Useful when multiple parts of the code need access to the same resource.
// Uses reference counting to track how many shared_ptr instances point to the same object.

// reference counting are used to track how many pointer are pointing to 
// the same object.
// when shared pointer is created it increament the refrence counting by one 
// its has very small memory.

class Employee {
  public:
  Employee() {
    std::cout << "Employee Recruited\n";
  }

  ~Employee() {
    std::cout << "Employee Got Kicked\n";
  }

};

int main() {

  // we can share resorce to each other 
  // like here remember its not creating like acutual copies 
  // its copying it means taking it ownership of that pointer

  std::shared_ptr<Employee> ptr1 = std::make_unique<Employee>();
  std::shared_ptr<Employee> ptr2 = ptr1;
  std::shared_ptr<Employee> ptr3 = ptr1;

  // we reset it here after tranfering ownership three times..
  ptr1.reset();

  // this tell how many times you transfer or give resources 
  // called reference count
  std::cout << ptr1.use_count() << '\n';
  std::cout << ptr2.use_count() << '\n';
  std::cout << ptr3.use_count() << '\n';

  return 0;
}