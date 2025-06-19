#include <iostream>
#include <memory>

// CIRCULAR REFERENCES & std::weak_ptr

// weak ptr works with share ptr 
// when we tranfer ownership of share ptr to weak ptr 
// weak ptr does not own it but hold a reference to it and does not 
// increase reference count 

// kinda like it weak ptr can take a peak in share ptr 
// and does not increase reference count

// Circular Reference
// Circular reference happen when a share pointer "A" point to 
// share Pointer "B" and "B" pointer share to "A".
// means A owns B and B owns A and kinda like loop it get stuck there
// and never freed memory causing memory leak

class B;

class A {
  public:

    std::shared_ptr<B> b_ptr;
    A() {
      std::cout << "A created\n";
    }
    ~A() {
      std::cout << "A Destroyed\n";
    }

};

class B {
  public:

    std::shared_ptr<A> a_ptr;
    B() {
      std::cout << "B created\n";
    }
    ~B() {
      std::cout << "B Destroyed\n";
    }

};

int main() {

  std::shared_ptr<A> a = std::make_shared<A>(); // reference count 1;
  std::shared_ptr<B> b = std::make_shared<B>(); // reference count 1;

  std::cout << a.use_count() << '\n';
  std::cout << b.use_count() << '\n';

  a->b_ptr = b; // A owns B
  b->a_ptr = a; // B owns A (circular dependency)

  // now a and b both have 
  // reference count 2;
  // when a and b goes out of scope the reference count 
  // remain 1 because A and B both still owns 1 here

  // TO FIX THIS WE USE WEAK POINTER
  
  return 0;
}
